// loop.h
#ifndef LOOP_H
#define LOOP_H

#include "parser.h" // Ensure ASTNode is defined
#include "lexer.h"

// Function declarations for loop handling
ASTNode *parseLoopStatement(Token *tokens, int *pos);
void runLoopStatement(ASTNode *node);

#endif
