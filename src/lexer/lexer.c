// lexer.c

#include "lexer.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// Function to get the next token from the source
Token getNextToken(const char *source, int *pos)
{
    Token token;
    // Skip whitespace and newlines
    while (source[*pos] == ' ' || source[*pos] == '\t' || source[*pos] == '\n' || source[*pos] == '\r')
    {
        (*pos)++;
    }

    // End of source
    if (source[*pos] == '\0')
    {
        token.type = TOKEN_EOF;
        strcpy(token.value, "EOF");
        return token;
    }

    // Operators and punctuation
    switch (source[*pos])
    {
    case '+':
        token.type = TOKEN_PLUS;
        strcpy(token.value, "+");
        (*pos)++;
        return token;
    case '-':
        token.type = TOKEN_MINUS;
        strcpy(token.value, "-");
        (*pos)++;
        return token;
    case '*':
        token.type = TOKEN_ASTERISK;
        strcpy(token.value, "*");
        (*pos)++;
        return token;
    case '/':
        token.type = TOKEN_SLASH;
        strcpy(token.value, "/");
        (*pos)++;
        return token;
    case '=':
        token.type = TOKEN_ASSIGN;
        strcpy(token.value, "=");
        (*pos)++;
        return token;
    case '<':
        if (source[*pos + 1] == '=')
        {
            token.type = TOKEN_LTE;
            strcpy(token.value, "<=");
            (*pos) += 2;
        }
        else
        {
            token.type = TOKEN_LT;
            strcpy(token.value, "<");
            (*pos)++;
        }
        return token;
    case '>':
        if (source[*pos + 1] == '=')
        {
            token.type = TOKEN_GTE;
            strcpy(token.value, ">=");
            (*pos) += 2;
        }
        else
        {
            token.type = TOKEN_GT;
            strcpy(token.value, ">");
            (*pos)++;
        }
        return token;
    case ';':
        token.type = TOKEN_SEMICOLON;
        strcpy(token.value, ";");
        (*pos)++;
        return token;
    case '(':
        token.type = TOKEN_LPAREN;
        strcpy(token.value, "(");
        (*pos)++;
        return token;
    case ')':
        token.type = TOKEN_RPAREN;
        strcpy(token.value, ")");
        (*pos)++;
        return token;
    case '{':
        token.type = TOKEN_LBRACE;
        strcpy(token.value, "{");
        (*pos)++;
        return token;
    case '}':
        token.type = TOKEN_RBRACE;
        strcpy(token.value, "}");
        (*pos)++;
        return token;
    }

    // Identifiers (variables) and numbers
    if (isalpha(source[*pos]))
    {
        int start = *pos;
        while (isalpha(source[*pos]) || isdigit(source[*pos]))
        {
            (*pos)++;
        }
        strncpy(token.value, &source[start], *pos - start);
        token.value[*pos - start] = '\0';
        token.type = TOKEN_IDENTIFIER;
        return token;
    }

    if (isdigit(source[*pos]))
    {
        int start = *pos;
        while (isdigit(source[*pos]))
        {
            (*pos)++;
        }
        strncpy(token.value, &source[start], *pos - start);
        token.value[*pos - start] = '\0';
        token.type = TOKEN_NUMBER;
        return token;
    }

    // Unknown token
    token.type = TOKEN_UNKNOWN;
    token.value[0] = source[*pos];
    token.value[1] = '\0';
    (*pos)++;
    return token;
}

// Function to run the lexer
void runLexer(const char *source)
{
    int pos = 0;
    Token token;
    do
    {
        token = getNextToken(source, &pos);
        if (token.type != TOKEN_EOF)
        {
            printf("Token: %s (Type: %d)\n", token.value, token.type);
        }
    } while (token.type != TOKEN_EOF);
}
