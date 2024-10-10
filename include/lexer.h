#ifndef LEXER_H
#define LEXER_H

typedef enum
{
    TOKEN_SET,
    TOKEN_IF,
    TOKEN_IDENTIFIER,
    TOKEN_STRING_LITERAL,
    TOKEN_NUMBER,
    TOKEN_PRINT,
    TOKEN_UNKNOWN
} TokenType;

typedef struct
{
    TokenType type;
    char value[50];
} Token;

Token getNextToken(const char *source, int *pos);
void runLexer(const char *source);

#endif // LEXER_H
