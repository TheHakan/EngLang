#include "lexer.h"
#include "parser.h"
#include "semantic.h"
#include <stdio.h>
#include <string.h>

void checkSemantic(ASTNode *node)
{
    if (node == NULL)
        return;

    // Perform a basic semantic check
    if (node->token.type == TOKEN_SET && node->left != NULL && node->right != NULL)
    {
        if (node->left->token.type != TOKEN_IDENTIFIER)
        {
            printf("Semantic Error: Left side of assignment must be an identifier.\n");
        }
        if (node->right->token.type != TOKEN_NUMBER)
        {
            printf("Semantic Error: Right side of assignment must be a number.\n");
        }
    }

    // Recursively check left and right subtrees
    checkSemantic(node->left);
    checkSemantic(node->right);
}
