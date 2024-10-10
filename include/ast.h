#ifndef AST_H
#define AST_H

#include "lexer.h" // Ensure lexer tokens are available

// Define the ASTNode structure used for the Abstract Syntax Tree (AST)
typedef struct ASTNode
{
    Token token;           // The token stored in this AST node
    struct ASTNode *left;  // Pointer to the left child (for binary operations)
    struct ASTNode *right; // Pointer to the right child (for binary operations)
} ASTNode;

#endif // AST_H
