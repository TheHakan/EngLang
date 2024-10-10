#ifndef PARSER_H
#define PARSER_H

#include "lexer.h" // Ensure lexer tokens are available
#include "ast.h"   // Include ASTNode definition

void runParser(const char *source);
ASTNode *parseAssignment(Token *tokens, int *pos);
void setVariableValue(const char *name, int value);  // Declaration for setVariableValue
int getVariableValue(const char *name);              // Declaration for getVariableValue
void parseAndRunPrint(Token *tokens, int *pos);      // Declaration for parseAndRunPrint

#endif // PARSER_H
