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

    // Assume simple expression: single token for now (either a number or identifier)
    node->token = tokens[*pos];
    (*pos)++;

    return node; // Return the expression node
}
