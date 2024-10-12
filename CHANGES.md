# CHANGES.md

## Version 0.2.1 (October 12, 2024)
### Enhancements and Fixes
- **Tokenization Improvements**:
  - Refined the token recognition system to handle variable assignments correctly (`a = 10`).
  - Improved token handling for `print` statements to resolve issues with parsing and execution.
  
- **Interpreter Update**:
  - Updated interpreter logic to handle assignments and output correctly. Now supports basic assignment (`a = 10`) and `print` functionality.

- **Makefile Update**:
  - Minor fixes in the `Makefile` to ensure automatic binary copying to `/usr/local/bin`.

### Fixes:
- Fixed the issue where the binary was not updated correctly when using the `make` command.
- Resolved token recognition issues causing `print` and assignment tokens to fail during execution.

---

## Version 0.2.0 (October 12, 2024)
### Major Refactor and Project Structure Update
- **Lexer Refactor**:
  - Refactored the lexer to split token recognition into distinct files under the `src/lexer/` directory.
  - Created subdirectories for each category of tokens:
    - **`control/`**: Added `token_eof.c`, `token_unknown.c` to handle EOF and unknown tokens.
    - **`keywords/`**: Added token files for keywords like `if`, `else`, `for`, `while`, `return`, etc.
    - **`literals/`**: Added token files for handling literals, such as identifiers, numbers, and strings.
    - **`logical_operators/`**: Added token files for logical operators (`&&`, `||`, `!`).
    - **`operators/`**: Added token files for arithmetic and comparison operators (`+`, `-`, `=`, `==`, etc.).
    - **`punctuation/`**: Added token files for punctuation (`;`, `,`, `{}`, `()`, etc.).

- **Parser Updates**:
  - Updated the parser to work with the new modularized token system.
  - Cleaned up the parser logic for handling assignment and print statements.
  - Fixed a bug causing incorrect token recognition for basic assignment statements like `a = 10`.

- **Makefile Update**:
  - Modified `Makefile` to support the new directory structure and automatically copy the compiled binary to `/usr/local/bin`.
  - Added rules to compile the newly separated source files for tokens in the lexer.

- **Project Structure**:
  - Updated the project’s directory tree to better organize tokens by type.
  - Created folders for various token categories (`control`, `keywords`, `literals`, `operators`, etc.) for easier project management.

### Minor Fixes:
- Fixed token recognition issues for `=` and other comparison operators.
- Improved readability of `parser.c` by cleaning up unused variables and warnings.

---

## Version 0.1.1 (October 10, 2024)
### Bug Fixes:
- Fixed an issue in the lexer where numbers and identifiers were not being tokenized correctly.
- Corrected the parser’s handling of arithmetic expressions involving multiple operators.

### Improvements:
- Enhanced error handling in the parser and lexer, including better messages for unrecognized tokens.

---

## Version 0.1.0 (October 10, 2024)
### Initial Release:
- Implemented basic syntax support for variable assignment (`a = 10`) and print statements (`print a`).
- Added basic control flow (`if` statements) and arithmetic operations.
- Created initial project structure with basic lexer, parser, and interpreter functionality.
- Introduced Makefile for building the project.