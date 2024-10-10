#include "parser.c" // Include the parser

void checkSemantic(ASTNode *node)
{
    if (node->token.type == TOKEN_SET)
    {
        // Example: You can add type checking here
        printf("Valid assignment: %s = %s\n", node->left->token.value, node->right->token.value);
    }
}

int main()
{
    // Example: After parsing, check the semantics of the AST
    const char *source = "Set x to 10";
    int pos = 0;
    Token tokens[10];
    int tokenPos = 0;

    while (pos < strlen(source))
    {
        tokens[tokenPos++] = getNextToken(source, &pos);
    }

    int parsePos = 0;
    ASTNode *ast = parseAssignment(tokens, &parsePos);
    checkSemantic(ast); // Check the validity of the AST

    return 0;
}
