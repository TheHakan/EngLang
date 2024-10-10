#include "lexer.h"
#include "parser.h"
#include <stdio.h>

int main()
{
    const char *sourceCode = "Set x to 10";
    printf("Running the interpreter...\n");

    // Call the parser (which calls the lexer)
    runParser(sourceCode);

    return 0;
}
