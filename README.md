# EngLang

**EngLang** is a free, open-source general-purpose programming language designed with simplicity and human-readability at its core. EngLang uses English-like syntax to minimize code complexity while maximizing performance and scalability. Built to be highly adaptable, EngLang supports a range of applications, from lightweight scripting tasks to performance-heavy projects. Its open-source nature encourages collaboration and evolution, ensuring that all modifications remain accessible to the developer community.

## Why EngLang?

EngLang was created to address some of the core challenges faced by modern programmers:

1. **Readability**: Many popular programming languages are heavily optimized for machines but can be difficult for humans to read and understand. EngLang's English-like syntax prioritizes readability, allowing developers to focus on logic rather than memorizing complex syntax rules.
   
2. **Ease of Use**: Writing code in EngLang should feel natural, especially for new programmers. By minimizing the learning curve with familiar keywords like `Set`, `Print`, `If`, and `Loop`, EngLang enables even beginners to write functional code quickly.

3. **Minimized Complexity**: EngLang strips away unnecessary complexity. Instead of requiring long boilerplate code, it emphasizes simplicity by allowing you to express logic in fewer lines of code.

4. **Open Source & Collaborative**: EngLang is not just a language; it's a community-driven project. As an open-source initiative, EngLang is built on the premise that contributions from developers around the world will evolve the language into something robust, flexible, and powerful.

## How EngLang Works

EngLang interprets high-level, human-readable instructions and executes them using a flexible, modular backend written in C. The language's structure is straightforward, borrowing elements from well-established paradigms while introducing innovative features that simplify the coding process.

Here’s how EngLang is designed:

### Core Features

- **English-Like Syntax**: Write code that reads like plain English. Examples of core statements include:
  - `Set x to 10`: Assigns a value to a variable.
  - `Print x`: Outputs the value of a variable.
  - `Print "Hello, World"`: Outputs a string.
  
- **Basic Constructs**:
  - **Variables**: Declare and manipulate variables using simple syntax.
  - **Conditionals (If Statements)**: Control flow based on conditions.
  - **Loops**: Repeat actions using loops like `While` and `For`.
  
- **Minimal Boilerplate**: No need for complex function declarations or imports to get started. Write only what you need.

- **Cross-Platform Compatibility**: EngLang can be compiled and run on various operating systems, including Linux, macOS, and Windows.

### EngLang Design

EngLang’s design philosophy is guided by the following principles:

1. **Simplicity**: EngLang minimizes the number of keywords and follows a straightforward grammar, allowing users to quickly write, understand, and debug their code. The goal is to keep programming simple and fun.
   
2. **Modularity**: The language is built with a modular approach in mind. Individual components like the lexer, parser, and interpreter are separate, which makes it easier to extend or modify the language as needed.

3. **Performance**: While ease of use is a primary focus, performance is not sacrificed. By using C as the underlying language for execution, EngLang retains the speed and efficiency of lower-level languages, making it suitable for more demanding applications.

4. **Open Collaboration**: EngLang is fully open-source, inviting developers to contribute and extend its capabilities. Whether it’s adding new language features, optimizing performance, or introducing new tools, contributions are welcome.

## What Can You Do With EngLang?

EngLang is built to accommodate various use cases, including:

- **Scripting and Automation**: Automate tasks with minimal code.
- **Prototyping**: Quickly draft and test your ideas without worrying about verbose syntax.
- **Teaching**: EngLang is an excellent educational tool for teaching programming concepts due to its readable and accessible syntax.
- **Application Development**: Though it’s lightweight, EngLang is designed to handle more complex tasks through its modular architecture and performance-oriented backend.

## Getting Started

To start using EngLang, follow these simple steps:

### Prerequisites
- A C compiler such as `gcc`
- Git for cloning the repository

### Installation

1. Clone the repository from GitHub:

    ```bash
    git clone https://github.com/TheHakan/EngLang.git
    cd EngLang
    ```

2. Build the language interpreter by running the following command:

    ```bash
    make
    ```

3. Optionally, install EngLang globally on your system for easy access:

    ```bash
    sudo cp eng /usr/local/bin/
    ```

### Running Your First EngLang Program

Create a `.eng` file with your program. Here's an example of a simple EngLang script:

```eng
Set x to 10
Print x
Print "Hello, World"
```

To run your program, simply execute the following command in your terminal:

```bash
eng <filename>
```

For example:

```bash
eng myprogram.eng
```

### EngLang Syntax Overview

Here are some basic syntax examples:

- **Variable Declaration and Assignment**:
    ```eng
    Set x to 5
    Set y to 10
    ```

- **Print Statements**:
    ```eng
    Print x          # Prints the value of x
    Print "Hello!"   # Prints the string "Hello!"
    ```

- **If Statements**:
    ```eng
    If x > 5
        Print "x is greater than 5"
    EndIf
    ```

- **Loops**:
    ```eng
    While x < 10
        Print x
        Set x to x + 1
    EndWhile
    ```

## Contribution

EngLang is an open-source project, and contributions are always welcome! Whether it's fixing bugs, adding new features, or improving documentation, you can help make EngLang even better.

### How to Contribute

1. Fork the repository and clone it locally.
2. Create a new branch for your feature or bug fix.
3. Commit your changes with clear messages.
4. Push the changes to your fork and submit a pull request.

### Code of Conduct

Please note that this project adheres to the [Contributor Covenant Code of Conduct](https://www.contributor-covenant.org/). By participating, you are expected to uphold this code.

## License

EngLang is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

EngLang is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with EngLang. If not, see <https://www.gnu.org/licenses/>.
