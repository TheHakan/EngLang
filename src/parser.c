#include "parser.h"
#include "lexer.h" // Include lexer declarations
#include <stdio.h>

void runParser(const char *source)
{
    printf("Parsing the source: %s\n", source);
    runLexer(source); // Call lexer logic from here
}
