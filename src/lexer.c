#include "lexer.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

Token getNextToken(const char *source, int *pos)
{
    Token token;

    // Skip any whitespace or newlines
    while (source[*pos] == ' ' || source[*pos] == '\t' || source[*pos] == '\n' || source[*pos] == '\r')
    {
        (*pos)++;
    }

    // Tokenization logic for other tokens (Set, Print, identifiers, etc.)
    if (strncmp(&source[*pos], "Set", 3) == 0)
    {
        token.type = TOKEN_SET;
        strcpy(token.value, "Set");
        *pos += 3;
    }
    else if (strncmp(&source[*pos], "Print", 5) == 0)
    {
        token.type = TOKEN_PRINT;
        strcpy(token.value, "Print");
        *pos += 5;
    }
    else if (isalpha(source[*pos])) // Identify variable names
    {
        token.type = TOKEN_IDENTIFIER;
        int start = *pos;
        while (isalpha(source[*pos]))
            (*pos)++; // Read the full identifier
        strncpy(token.value, &source[start], *pos - start);
        token.value[*pos - start] = '\0';
    }
    else if (isdigit(source[*pos])) // Identify numbers
    {
        token.type = TOKEN_NUMBER;
        int start = *pos;
        while (isdigit(source[*pos]))
            (*pos)++;
        strncpy(token.value, &source[start], *pos - start);
        token.value[*pos - start] = '\0';
    }
    else
    {
        token.type = TOKEN_UNKNOWN;
        token.value[0] = source[*pos];
        token.value[1] = '\0';
        (*pos)++;
    }

    return token;
}

// Run the lexer and print tokens
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
