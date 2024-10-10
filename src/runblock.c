#include "ast.h"
#include <stdio.h>

void runBlock(ASTNode *block)
{
    if (block != NULL)
    {
        // For now, just run the single statement (in reality, you'd loop through statements)
        runLoopStatement(block->left); // Example of running a loop or other statement
    }
}
