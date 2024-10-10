#include "parser.h"
#include "ast.h"
#include <stdlib.h>
#include <stdio.h>

// Parse a block of statements (simplified to handle a single assignment for now)
ASTNode *parseBlock(Token *tokens, int *pos)
{
    ASTNode *blockNode = malloc(sizeof(ASTNode));
    if (blockNode == NULL)
    {
        printf("Memory allocation failed for ASTNode (block).\n");
        return NULL;
    }

    blockNode->left = parseAssignment(tokens, pos); // Use the correct function

    return blockNode;
}
