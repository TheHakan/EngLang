# Compiler settings
CC = gcc
CFLAGS = -Wall -Iinclude

# Source files organized by subdirectories
SRC = src/lexer/lexer.c src/parser/parser.c src/interpreter/interpreter.c \
      src/semantic.c src/codegen.c src/if.c src/loop.c \
      src/expression.c src/block.c src/evaluate.c src/runblock.c

# Object files derived from the source files
OBJ = $(SRC:.c=.o)

# Output executable
TARGET = eng

# Default target
all: $(TARGET) install

# Linking the object files to produce the final executable
$(TARGET): $(OBJ)
	$(CC) -o $@ $(OBJ)

# Install the compiled binary to /usr/local/bin
install: $(TARGET)
	sudo cp $(TARGET) /usr/local/bin/

# Rule to compile each source file into an object file
src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f src/**/*.o $(TARGET)

# Rule to remove compiled files
clean-build:
	rm -f build/*

# Additional rule to clean object files, binaries, and distribution files
dist-clean: clean clean-build
	rm -rf dist/*
