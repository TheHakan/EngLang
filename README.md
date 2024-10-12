# EngLang

**EngLang** is a free, open-source, general-purpose programming language designed to make programming as intuitive and accessible as possible. By embracing simplicity and human-readable syntax, EngLang allows users to write code in a way that closely resembles natural English sentences. Whether you're a complete beginner or an experienced developer, EngLang aims to provide a seamless and enjoyable coding experience.

## Table of Contents

- [Introduction](#introduction)
- [Why EngLang?](#why-englang)
  - [Simplicity and Readability](#simplicity-and-readability)
  - [Accessibility for Beginners](#accessibility-for-beginners)
  - [Community-Driven Development](#community-driven-development)
  - [Cross-Platform Compatibility](#cross-platform-compatibility)
- [Core Principles](#core-principles)
  - [Free and Open Source](#free-and-open-source)
  - [Simplicity](#simplicity)
  - [Collaborative Growth](#collaborative-growth)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
  - [Your First EngLang Program](#your-first-englang-program)
- [Language Features](#language-features)
  - [Variables](#variables)
  - [Data Types](#data-types)
  - [Operators](#operators)
  - [Control Structures](#control-structures)
  - [Loops](#loops)
  - [Functions (Planned)](#functions-planned)
- [Project Structure](#project-structure)
- [Roadmap](#roadmap)
  - [Short-Term Goals](#short-term-goals)
  - [Long-Term Vision](#long-term-vision)
- [Contribution Guidelines](#contribution-guidelines)
  - [How to Contribute](#how-to-contribute)
  - [What We're Looking For](#what-were-looking-for)
- [License](#license)

## Introduction

Programming languages have traditionally been seen as cryptic and inaccessible to those without a technical background. **EngLang** seeks to change that by introducing a language that reads almost like plain English. By lowering the barrier to entry, we hope to empower more people to learn programming and bring their ideas to life.

**Please note:** EngLang is in its **very early stages of development**. We are actively seeking feedback, ideas, and contributions to help shape the future of this language.

## Why EngLang?

### Simplicity and Readability

EngLang prioritizes human readability above all else. By using straightforward English phrases and reducing syntactic clutter, code written in EngLang is easier to read and understand.

**Example:**

```englang
Set x to 10
If x is greater than 5
    Print "x is large"
EndIf
```

### Accessibility for Beginners

Learning to code can be intimidating. EngLang reduces this intimidation by using familiar language constructs, allowing beginners to focus on learning programming concepts rather than complex syntax.

### Community-Driven Development

EngLang is an **open-source** project that thrives on community involvement. We believe that the best software is built collaboratively, and we welcome contributions from developers of all skill levels.

### Cross-Platform Compatibility

Built with portability in mind, EngLang runs on all major operating systems, including **Linux**, **macOS**, and **Windows**. The interpreter is written in C, ensuring efficient performance across platforms.

## Core Principles

### Free and Open Source

EngLang is released under the GNU General Public License v3.0. We are committed to keeping EngLang free for everyone to use, modify, and distribute.

### Simplicity

We aim to keep the language as simple as possible, avoiding unnecessary complexity while providing the tools needed to build functional programs.

### Collaborative Growth

We encourage the community to participate in EngLang's development. Your ideas, feedback, and contributions are invaluable to us.

## Getting Started

### Prerequisites

- A C compiler (e.g., `gcc`)
- `make` utility
- Git (for cloning the repository)

### Installation

1. **Clone the Repository**

   ```bash
   git clone https://github.com/TheHakan/EngLang.git
   cd EngLang
   ```

2. **Build the Interpreter**

   ```bash
   make
   ```

3. **(Optional) Install Globally**

   ```bash
   sudo cp eng /usr/local/bin/
   ```

### Your First EngLang Program

Create a file named `hello.eng`:

```englang
Print "Hello, World!"
```

Run the program:

```bash
eng hello.eng
```

**Expected Output:**

```
Hello, World!
```

## Language Features

### Variables

Declare and assign variables using the `Set` keyword.

```englang
Set age to 25
Set name to "Alice"
```

### Data Types

EngLang currently supports:

- Integers
- Floating-point numbers
- Strings
- Booleans (planned)

### Operators

- Arithmetic: `+`, `-`, `*`, `/`
- Comparison: `is equal to`, `is not equal to`, `is greater than`, `is less than`

**Example:**

```englang
Set sum to 5 + 3
If sum is equal to 8
    Print "Correct"
EndIf
```

### Control Structures

#### If Statements

```englang
If x is greater than 10
    Print "x is large"
Else
    Print "x is small"
EndIf
```

#### Switch Cases (Planned)

```englang
Switch day
    Case "Monday"
        Print "Start of the week"
    Case "Friday"
        Print "End of the week"
    Default
        Print "Midweek"
EndSwitch
```

### Loops

#### While Loops

```englang
Set i to 0
While i is less than 5
    Print i
    Set i to i + 1
EndWhile
```

#### For Loops (Planned)

```englang
For each item in list
    Print item
EndFor
```

### Functions (Planned)

Defining reusable code blocks.

```englang
Function greet(name)
    Print "Hello, " + name
EndFunction

greet("Alice")
```

## Project Structure

This section provides an overview of the project’s file structure and explains the purpose of each directory and file.

### Top-Level Files:
- **`CHANGES.md`**: This file tracks all the project’s changes, updates, and new features. Every time you push a commit, ensure to document the modifications here for easy reference.
  
- **`CONTRIBUTING.md`**: This file offers guidelines for developers interested in contributing to EngLang. It explains the process of submitting pull requests, writing tests, and adhering to coding standards.
  
- **`LICENSE`**: Clearly defines the licensing terms under which this project is released. It protects both developers and users, ensuring clarity about the usage, distribution, and modification of the software.

- **`README.md`**: Provides general information about the EngLang project, its purpose, and how to get started. It also includes instructions for building, contributing, and any other relevant details.

- **`TODO.md`**: This file contains upcoming tasks, features, and improvements. It acts as a roadmap for the project's future direction.

### Key Directories:
- **`bin/`**: This directory is reserved for compiled binaries or executables. When users compile or build the project, the resulting binaries (compiled programs) will be stored here.

- **`build/`**: Contains temporary or intermediate build artifacts, such as the `mylanguage.exe`. These artifacts are essential during the development process but are not intended to be distributed.

- **`dist/`**: This directory is currently empty but will be used to store the final, distributable version of the project. When the project is packaged (as ZIP files, installers, etc.), they will be placed here.

- **`docs/`**: Contains guides, manuals, or any documentation related to the project. The `GUIDE.md` explains how to use EngLang and contribute to it. You can expand this directory to include more user or developer guides in the future.

- **`grammar/`**: Stores the grammar files that define the syntax of EngLang. This is an important directory as it helps in the lexical analysis and parsing of EngLang programs.

- **`include/`**: Contains all the header files (e.g., `lexer.h`, `parser.h`). These files declare functions, structures, and variables that are shared across different parts of the project. Having them in a central directory keeps the project modular and easy to maintain.

- **`src/`**: This directory houses the actual source code files for EngLang. The source code is organized into subdirectories, such as:
  - **`interpreter/`**: Contains the code responsible for interpreting EngLang programs.
  - **`lexer/`**: Manages the lexical analysis (tokenization) of the source code.
  - **`parser/`**: Handles the parsing of tokens into a syntax tree for execution.

- **`tests/`**: This directory holds all test-related files, such as `test.eng` and `test_runner.c`. It ensures that the project is tested regularly for correctness. Unit tests and functional tests should be stored here to guarantee code quality.

## Roadmap

### Short-Term Goals

- **Implement Functions:** Allow users

 to define and call functions.
- **Expand Data Types:** Introduce arrays, lists, and dictionaries.
- **Error Handling:** Implement try-catch blocks for robust programs.
- **Standard Library:** Build a library for common tasks like string manipulation and file I/O.

### Long-Term Vision

- **Object-Oriented Features:** Introduce classes and objects.
- **Concurrency Support:** Enable multi-threading capabilities.
- **Package Manager:** Develop a system for distributing and installing EngLang packages.
- **Integrated Development Environment (IDE):** Create an IDE tailored for EngLang.

## Contribution Guidelines

We are excited to have you contribute! EngLang is open to all kinds of ideas and contributions.

### How to Contribute

1. **Fork the Repository**

   Click the "Fork" button at the top right corner of the repository page.

2. **Clone Your Fork**

   ```bash
   git clone https://github.com/YourUsername/EngLang.git
   cd EngLang
   ```

3. **Create a New Branch**

   ```bash
   git checkout -b feature-or-bugfix-name
   ```

4. **Make Your Changes**

   Ensure your code follows the project's coding standards.

5. **Commit and Push**

   ```bash
   git add .
   git commit -m "Description of your changes"
   git push origin feature-or-bugfix-name
   ```

6. **Submit a Pull Request**

   Go to the original repository and click on "New Pull Request."

### What We're Looking For

- **New Features:** Implement planned features or propose new ones.
- **Bug Fixes:** Identify and fix bugs.
- **Documentation:** Improve or expand the documentation.
- **Testing:** Write unit tests to ensure code reliability.
- **Optimizations:** Enhance performance and efficiency.

## License

EngLang is licensed under the **GNU General Public License v3.0**. You are free to use, modify, and distribute this software under the terms of this license.

For more details, see the [LICENSE](LICENSE) file or visit [GNU's official website](https://www.gnu.org/licenses/gpl-3.0.en.html).