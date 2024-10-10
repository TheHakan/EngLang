#ifndef BLOCK_H
#define BLOCK_H

#include "ast.h"
#include "parser.h"

ASTNode *parseBlock(Token *tokens, int *pos);

#endif
