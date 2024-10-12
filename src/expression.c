// expression.c

#include "ast.h"
#include "lexer.h"
#include <stdlib.h>
#include <stdio.h>

ASTNode *parseExpression(Token *tokens, int *pos)
{
    // Allocate a new ASTNode
    ASTNode *node = malloc(sizeof(ASTNode));
    if (node == NULL)
    {
        printf("Memory allocation failed for ASTNode (expression).\n");
        return NULL;
    }

    // Check if the token is a number or an identifier (e.g., variable name)
    if (tokens[*pos].type == TOKEN_NUMBER || tokens[*pos].type == TOKEN_IDENTIFIER)
    {
        node->token = tokens[*pos];
        (*pos)++;
    }
    else
    {
        printf("Error: Expected a number or identifier in expression.\n");
        free(node);
        return NULL;
    }

    // Now handle binary operators (e.g., +, -, *, /)
    while (tokens[*pos].type == TOKEN_PLUS || tokens[*pos].type == TOKEN_MINUS ||
           tokens[*pos].type == TOKEN_ASTERISK || tokens[*pos].type == TOKEN_SLASH)
    {
        // Allocate a new node for the operator
        ASTNode *operatorNode = malloc(sizeof(ASTNode));
        if (operatorNode == NULL)
        {
            printf("Memory allocation failed for ASTNode (operator).\n");
            free(node);
            return NULL;
        }

        // Store the operator token
        operatorNode->token = tokens[*pos];
        (*pos)++;

        // Recursively parse the right-hand side of the expression
        operatorNode->right = parseExpression(tokens, pos);
        if (operatorNode->right == NULL)
        {
            printf("Error: Failed to parse the right-hand side of the expression.\n");
            free(node);
            free(operatorNode);
            return NULL;
        }

        // The left side is the current node (already parsed)
        operatorNode->left = node;
        node = operatorNode; // Update the node to point to the operator node
    }

    return node; // Return the parsed expression node (AST)
}
