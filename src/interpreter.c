#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Prepare the filename
    char filename[100]; // Adjust size as needed
    strcpy(filename, argv[1]);

    // Append ".eng" if not provided
    if (strstr(filename, ".eng") == NULL)
    {
        strcat(filename, ".eng");
    }

    // Open the .eng file
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error: File '%s' not found.\n", filename);
        return 1;
    }

    // Find out the file size
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    // Dynamically allocate buffer based on file size
    char *sourceCode = (char *)malloc((fileSize + 1) * sizeof(char));
    if (sourceCode == NULL)
    {
        printf("Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    // Read file content into sourceCode buffer
    fread(sourceCode, sizeof(char), fileSize, file);
    sourceCode[fileSize] = '\0'; // Null-terminate the string
    fclose(file);

    printf("Running the interpreter for: %s\n", filename);

    // Run the parser
    runParser(sourceCode);

    // Free the allocated memory
    free(sourceCode);
    return 0;
}
