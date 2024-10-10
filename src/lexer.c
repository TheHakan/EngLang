#include "lexer.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>

Token getNextToken(const char *source, int *pos)
{
    Token token;

    // Skip any whitespace
    while (source[*pos] == ' ' || source[*pos] == '\t' || source[*pos] == '\n')
    {
        (*pos)++;
    }

    // Check for the keyword "Set"
    if (strncmp(&source[*pos], "Set", 3) == 0)
    {
        token.type = TOKEN_SET;
        strcpy(token.value, "Set");
        *pos += 3;
    }
    // Check for the keyword "to"
    else if (strncmp(&source[*pos], "to", 2) == 0)
    {
        token.type = TOKEN_IDENTIFIER;
        strcpy(token.value, "to");
        *pos += 2;
    }
    // Check for an identifier (like variable names: "x")
    else if (isalpha(source[*pos]))
    {
        token.type = TOKEN_IDENTIFIER;
        token.value[0] = source[*pos];
        token.value[1] = '\0';
        (*pos)++;
    }
    // Check for a number (like "10")
    else if (isdigit(source[*pos]))
    {
        int start = *pos;
        while (isdigit(source[*pos]))
        {
            (*pos)++;
        }
        strncpy(token.value, &source[start], *pos - start);
        token.value[*pos - start] = '\0';
        token.type = TOKEN_NUMBER;
    }
    // If it's an unknown character
    else
    {
        token.type = TOKEN_UNKNOWN;
        strcpy(token.value, "?");
        (*pos)++;
    }

    return token;
}

void runLexer(const char *source)
{
    int pos = 0;
    Token token;

    while (pos < strlen(source))
    {
        token = getNextToken(source, &pos);
        printf("Token: %s\n", token.value);
    }
}
