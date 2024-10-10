#include "semantic.c"

void generateCode(ASTNode *node)
{
    if (node->token.type == TOKEN_SET)
    {
        printf("MOV %s, %s\n", node->left->token.value, node->right->token.value);
    }
}

int main()
{
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
    generateCode(ast); // Generate code (example output: assembly-like instructions)

    return 0;
}
