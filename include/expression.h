#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "ast.h"
ASTNode *parseExpression(Token *tokens, int *pos);

#endif
