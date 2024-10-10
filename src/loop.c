#include "loop.h"
#include "parser.h"
#include "lexer.h"
#include "semantic.h"
#include <stdio.h>
#include <stdlib.h>

// If these functions are defined elsewhere, declare them as extern
extern ASTNode *parseExpression(Token *tokens, int *pos);
extern ASTNode *parseBlock(Token *tokens, int *pos);
extern int evaluateExpression(ASTNode *expression);
extern void runBlock(ASTNode *block);

// Parse a loop statement (e.g., while loop)
ASTNode *parseLoopStatement(Token *tokens, int *pos)
{
    ASTNode *loopNode = malloc(sizeof(ASTNode));
    loopNode->token = tokens[*pos];
    (*pos)++; // Skip 'while' or 'for' token

    // Parse the loop condition
    loopNode->left = parseExpression(tokens, pos);

    // Parse the loop body
    loopNode->right = parseBlock(tokens, pos);

    return loopNode;
}

// Execute a loop statement
void runLoopStatement(ASTNode *node)
{
    while (evaluateExpression(node->left))
    {
        runBlock(node->right); // Run the block repeatedly as long as the condition is true
    }
}
