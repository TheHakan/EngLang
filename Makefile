# Compiler settings
CC = gcc
CFLAGS = -Wall -Iinclude

# Source and object files
SRC = src/lexer.c src/parser.c src/interpreter.c src/semantic.c src/codegen.c
OBJ = $(SRC:.c=.o)

# Output executable
TARGET = build/mylanguage.exe

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJ)
	$(CC) -o $@ $(OBJ)

# Compiling each source file into an object file
src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f src/*.o $(TARGET)
