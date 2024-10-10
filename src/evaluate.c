#include "ast.h"
#include <stdio.h>

int evaluateExpression(ASTNode *expression)
{
    // For simplicity, assume the expression is a number
    if (expression->token.type == TOKEN_NUMBER)
    {
        return atoi(expression->token.value); // Convert string to integer
    }
    else
    {
        printf("Unsupported expression type for evaluation.\n");
        return 0; // Default return value
    }
}
