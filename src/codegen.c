#include "semantic.h"
#include "parser.h"
#include "lexer.h" // Add this include to get access to TOKEN_SET
#include <stdio.h>

// Assuming tokenize is a lexer function that tokenizes the input source
extern int tokenize(const char *source, Token *tokens);

// Assuming parseAssignment is a parser function that creates an AST
extern ASTNode *parseAssignment(Token *tokens, int *pos);

void generateCode(ASTNode *node)
{
    if (node->token.type == TOKEN_SET)
    {
        printf("MOV %s, %s\n", node->left->token.value, node->right->token.value);
    }
}

// int main()
// {
//     const char *source = "Set x to 10";
//     Token tokens[10];
//     int tokenPos = 0;

//     int tokenCount = tokenize(source, tokens);
//     int parsePos = 0;
//     ASTNode *ast = parseAssignment(tokens, &parsePos);

//     generateCode(ast); // Generate code based on the AST

//     return 0;
// }
