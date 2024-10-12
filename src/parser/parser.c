// parser.c

#include "parser.h"
#include "lexer.h"
#include "semantic.h"
#include "if.h"
#include "loop.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simple symbol table for storing variables and their values
typedef struct
{
    char name[50];
    int value;
} Variable;

Variable symbolTable[100];
int variableCount = 0;

// Helper function to find a variable in the symbol table
int getVariableValue(const char *name)
{
    for (int i = 0; i < variableCount; i++)
    {
        if (strcmp(symbolTable[i].name, name) == 0)
        {
            return symbolTable[i].value;
        }
    }
    printf("Error: Variable '%s' not found.\n", name);
    exit(1);
}

// Helper function to set a variable value in the symbol table
void setVariableValue(const char *name, int value)
{
    for (int i = 0; i < variableCount; i++)
    {
        if (strcmp(symbolTable[i].name, name) == 0)
        {
            symbolTable[i].value = value;
            return;
        }
    }
    strcpy(symbolTable[variableCount].name, name);
    symbolTable[variableCount].value = value;
    variableCount++;
}

// Tokenize the input source code into tokens
int tokenize(const char *source, Token **tokens, int *tokenArraySize)
{
    int pos = 0;
    int tokenPos = 0;
    Token token;
    *tokens = malloc((*tokenArraySize) * sizeof(Token));

    while (pos < strlen(source))
    {
        token = getNextToken(source, &pos);

        if (tokenPos >= *tokenArraySize)
        {
            *tokenArraySize *= 2;
            Token *newTokens = realloc(*tokens, (*tokenArraySize) * sizeof(Token));
            if (newTokens == NULL)
            {
                printf("Memory reallocation for tokens failed.\n");
                free(*tokens);
                return -1;
            }
            *tokens = newTokens;
        }

        (*tokens)[tokenPos++] = token;
    }
    return tokenPos;
}

// Parse an assignment statement
ASTNode *parseAssignment(Token *tokens, int *pos)
{
    ASTNode *node = malloc(sizeof(ASTNode));
    if (node == NULL)
    {
        printf("Memory allocation failed for ASTNode.\n");
        return NULL;
    }

    node->left = malloc(sizeof(ASTNode));
    node->left->token = tokens[*pos];
    (*pos)++;

    if (tokens[*pos].type != TOKEN_ASSIGN)
    {
        printf("Error: Expected '=' after variable name.\n");
        free(node->left);
        free(node);
        return NULL;
    }
    (*pos)++;

    node->right = malloc(sizeof(ASTNode));
    node->right->token = tokens[*pos];
    (*pos)++;

    setVariableValue(node->left->token.value, atoi(node->right->token.value));

    return node;
}

// Parse and run a print statement
void parseAndRunPrint(Token *tokens, int *pos)
{
    (*pos)++;
    Token next = tokens[*pos];

    if (next.type == TOKEN_IDENTIFIER)
    {
        int value = getVariableValue(next.value);
        printf("%d\n", value);
        (*pos)++;
    }
    else if (next.type == TOKEN_STRING_LITERAL)
    {
        printf("%s\n", next.value);
        (*pos)++;
    }
    else
    {
        printf("Error: Expected an identifier or string literal after 'print'.\n");
        (*pos)++;
    }
}

// Main parser loop
void runParser(const char *source)
{
    Token *tokens;
    int tokenArraySize = 10;
    int tokenCount = tokenize(source, &tokens, &tokenArraySize);

    if (tokenCount == -1)
    {
        printf("Tokenization failed due to memory issues.\n");
        return;
    }

    int pos = 0;
    while (pos < tokenCount)
    {
        Token currentToken = tokens[pos];

        if (currentToken.type == TOKEN_UNKNOWN && (strcmp(currentToken.value, "\n") == 0 || strcmp(currentToken.value, "\r") == 0 || strcmp(currentToken.value, "") == 0))
        {
            pos++;
            continue;
        }

        if (currentToken.type == TOKEN_EOF)
        {
            break;
        }

        if (currentToken.type == TOKEN_IDENTIFIER && tokens[pos + 1].type == TOKEN_ASSIGN)
        {
            parseAssignment(tokens, &pos); // No need to store the return value if it is unused
        }
        else if (currentToken.type == TOKEN_PRINT)
        {
            parseAndRunPrint(tokens, &pos);
        }
        else
        {
            printf("Unknown statement at position %d (token: %s)\n", pos, tokens[pos].value);
            pos++;
        }
    }
    free(tokens);
}
