# Compiler settings
CC = gcc
CFLAGS = -Wall -Iinclude

# Source and object files
SRC = src/lexer.c src/parser.c src/interpreter.c src/semantic.c src/codegen.c src/if.c src/loop.c src/expression.c src/block.c src/evaluate.c src/runblock.c
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

# Compiling each source file into an object file
src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f src/*.o $(TARGET)
