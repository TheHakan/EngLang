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
    // If variable doesn't exist, add it to the symbol table
    strcpy(symbolTable[variableCount].name, name);
    symbolTable[variableCount].value = value;
    variableCount++;
}

// Tokenize the input source code into tokens with dynamic resizing
int tokenize(const char *source, Token **tokens, int *tokenArraySize)
{
    int pos = 0;
    int tokenPos = 0;
    Token token;

    // Initialize tokens array
    *tokens = malloc((*tokenArraySize) * sizeof(Token));
    if (*tokens == NULL)
    {
        printf("Memory allocation failed for tokens.\n");
        return -1; // Return -1 to indicate failure
    }

    while (pos < strlen(source))
    {
        // Get the next token
        token = getNextToken(source, &pos);

        // If the token array size is exceeded, reallocate with more space
        if (tokenPos >= *tokenArraySize)
        {
            *tokenArraySize *= 2; // Double the array size
            Token *newTokens = realloc(*tokens, (*tokenArraySize) * sizeof(Token));
            if (newTokens == NULL)
            {
                printf("Memory reallocation for tokens failed.\n");
                free(*tokens); // Free old memory
                return -1;
            }
            *tokens = newTokens; // Update to the new memory address
        }

        (*tokens)[tokenPos++] = token;
    }

    return tokenPos; // Return the number of tokens
}

// Parse an assignment statement (e.g., "Set x to 10")
ASTNode *parseAssignment(Token *tokens, int *pos)
{
    // Allocate a new ASTNode for the assignment
    ASTNode *node = malloc(sizeof(ASTNode));
    if (node == NULL)
    {
        printf("Memory allocation failed for ASTNode.\n");
        return NULL;
    }

    // Check if the current token is "Set"
    node->token = tokens[*pos];
    (*pos)++;

    if (node->token.type == TOKEN_SET)
    {
        // Parse the variable (left-hand side)
        node->left = malloc(sizeof(ASTNode));
        if (node->left == NULL)
        {
            printf("Memory allocation failed for ASTNode (left).\n");
            free(node); // Free the parent node in case of failure
            return NULL;
        }

        node->left->token = tokens[*pos];
        (*pos)++;

        // Check if the next token is "to"
        Token next = tokens[*pos];
        if (next.type == TOKEN_IDENTIFIER && strcmp(next.value, "to") == 0)
        {
            (*pos)++; // Skip the "to" token

            // Parse the right-hand side (value or identifier)
            Token valueToken = tokens[*pos];
            if (valueToken.type == TOKEN_NUMBER || valueToken.type == TOKEN_IDENTIFIER)
            {
                node->right = malloc(sizeof(ASTNode));
                if (node->right == NULL)
                {
                    printf("Memory allocation failed for ASTNode (right).\n");
                    free(node->left); // Free left node
                    free(node);       // Free parent node
                    return NULL;
                }

                node->right->token = valueToken;
                (*pos)++;
            }
            else
            {
                printf("Error: Expected a number or identifier after 'to'.\n");
                free(node->left); // Cleanup
                free(node);
                return NULL;
            }
        }
        else
        {
            printf("Error: Expected 'to' after the variable.\n");
            free(node->left); // Cleanup
            free(node);
            return NULL;
        }
    }
    else
    {
        printf("Error: Expected 'Set' token at the start.\n");
        free(node); // Cleanup
        return NULL;
    }

    return node; // Return the constructed AST node
}

// Parse and run a Print statement
void parseAndRunPrint(Token *tokens, int *pos)
{
    (*pos)++; // Skip the "Print" token

    Token next = tokens[*pos];

    if (next.type == TOKEN_IDENTIFIER)
    {
        int value = getVariableValue(next.value); // Get the variable's value from the symbol table
        printf("%d\n", value);                    // Print the value
        (*pos)++;
    }
    else if (next.type == TOKEN_STRING_LITERAL)
    {
        printf("%s\n", next.value); // Print the string
        (*pos)++;
    }
    else
    {
        printf("Error: Expected an identifier or string literal after 'Print'.\n");
        (*pos)++;
    }
}

// parser.c (ensure you skip any blank tokens or line breaks)
void runParser(const char *source)
{
    printf("Running the interpreter for: %s\n", source);

    // Initialize dynamic token array
    Token *tokens;
    int tokenArraySize = 10; // Initial size
    int tokenCount = tokenize(source, &tokens, &tokenArraySize);

    // Check if tokenization failed
    if (tokenCount == -1)
    {
        printf("Tokenization failed due to memory issues.\n");
        return;
    }

    int pos = 0;
    while (pos < tokenCount)
    {
        Token currentToken = tokens[pos];

        // Skip tokens that are empty or represent line breaks
        if (currentToken.type == TOKEN_UNKNOWN && (strcmp(currentToken.value, "\n") == 0 || strcmp(currentToken.value, "\r") == 0 || strcmp(currentToken.value, "") == 0))
        {
            pos++; // Skip to the next token
            continue;
        }

        // Process assignment and print statements
        if (currentToken.type == TOKEN_SET)
        {
            ASTNode *assignment = parseAssignment(tokens, &pos);
            if (assignment != NULL)
            {
                setVariableValue(assignment->left->token.value, atoi(assignment->right->token.value));
            }
        }
        else if (currentToken.type == TOKEN_PRINT)
        {
            parseAndRunPrint(tokens, &pos);
        }
        else
        {
            printf("Unknown statement at position %d (token: %s).\n", pos, tokens[pos].value);
            pos++;
        }
    }

    // Free the token array
    free(tokens);
}
