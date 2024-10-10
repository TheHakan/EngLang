#include "if.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function handles the parsing and evaluation of an if statement
void handleIfStatement(Token *tokens, int *pos)
{
    printf("Evaluating if statement...\n");

    // Check for the "if" keyword
    if (tokens[*pos].type == TOKEN_IF)
    {
        (*pos)++;

        // Evaluate the condition (for simplicity, we'll just assume a boolean literal like "true" or "false")
        if (strcmp(tokens[*pos].value, "true") == 0)
        {
            printf("Condition is true, executing if block.\n");
            (*pos)++;

            // Execute the statement in the if block (e.g., a print statement)
            if (tokens[*pos].type == TOKEN_PRINT)
            {
                (*pos)++;
                printf("%s\n", tokens[*pos].value);
                (*pos)++;
            }
        }
        else if (strcmp(tokens[*pos].value, "false") == 0)
        {
            printf("Condition is false, skipping if block.\n");
            (*pos)++;
        }
        else
        {
            printf("Error: Invalid condition in if statement.\n");
        }
    }
    else
    {
        printf("Error: Expected 'if' keyword.\n");
    }
}
