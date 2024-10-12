#ifndef LEXER_H
#define LEXER_H

// Define the types of tokens that will be recognized by the lexer
typedef enum
{
    // Keywords
    // TOKEN_SET,    // 'set' to = todo
    TOKEN_PRINT,  // 'print'
    TOKEN_IF,     // 'if'
    TOKEN_ELSE,   // 'else'
    TOKEN_WHILE,  // 'while'
    TOKEN_FOR,    // 'for'
    TOKEN_RETURN, // 'return'

    // Identifiers and literals
    TOKEN_IDENTIFIER,     // Variable names
    TOKEN_NUMBER,         // Numbers
    TOKEN_STRING_LITERAL, // Strings in quotes

    // Operators
    TOKEN_PLUS,      // '+'
    TOKEN_MINUS,     // '-'
    TOKEN_ASTERISK,  // '*'
    TOKEN_SLASH,     // '/'
    TOKEN_ASSIGN,    // '='
    TOKEN_EQUAL,     // '=='
    TOKEN_NOT_EQUAL, // '!='
    TOKEN_LT,        // '<'
    TOKEN_GT,        // '>'
    TOKEN_LTE,       // '<='
    TOKEN_GTE,       // '>='

    // Logical Operators
    TOKEN_AND, // '&&'
    TOKEN_OR,  // '||'
    TOKEN_NOT, // '!'

    // Punctuation
    TOKEN_LPAREN,    // '('
    TOKEN_RPAREN,    // ')'
    TOKEN_LBRACE,    // '{'
    TOKEN_RBRACE,    // '}'
    TOKEN_SEMICOLON, // ';'
    TOKEN_COMMA,     // ','

    // End of file and unknown token
    TOKEN_EOF,    // End of input
    TOKEN_UNKNOWN // Unrecognized token
} TokenType;

// Token structure to store type and value
typedef struct
{
    TokenType type;
    char value[50]; // Store the token's actual value (e.g., variable names, numbers)
} Token;

// Function declarations
Token getNextToken(const char *source, int *pos);
void runLexer(const char *source);

#endif // LEXER_H
