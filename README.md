# GNC

#### This is a simple programming language using flex and bison tools, C, and C++.
#### It's similar to C programming language but not exactly it.
#### The name "GNC" stands for "GNC's not C" (yes like GNU).

## Getting Started

Clone the repository to your local machine

    https://github.com/AhmedMaher309/Programming-language.git


Install Flex and Bison if they are not already installed. They can be installed on Ubuntu distro using the following commands:
    
    sudo apt install flex
    sudo apt install bison

install gcc compilers if not already installed on your machine using the following commands:
    
    sudo apt install build-essential
    sudo apt-get install manpages-dev

## Running the project

Build the binary file using the following command:

    make build

To clean up the build artifacts, run the following command:
    
    make clean

**Note:** If you'd like to build without printing all the build information and clean the build artifacts automatically, run the following command:

    make cleanbuild

To run the built binary, run the command:

    make run

* **"IN="** is an optional argument to set the name of the input file in the "testcases/" directory. (Defaults to IN=testcases/input.txt)
**Note:** If the input file is not found in the "testcases/" directory, the program defaults to input from the terminal.

* **"OUT="** is an optional argument to set the name of the output file in the "testcases/" directory. (Defaults to OUT=testcases/output.txt)
**Note:** If the output file is not found in the "testcases/" directory, the program defaults to output to the terminal.

To clear the project (delete the binary file, build artifacts, and input/output files), run the following command:

    make clear


## Features

The programming language implemented in this project includes the following features:

    Arithmetic operations (+, -, *, /)
    Comparison operators (==, !=, <, >, <=, >=)
    Variables assignment and retrieval
    Conditional statements (if-else)
    Loops (for, while)
    Functions and procedure definitions and calls
    Error handling and reporting


## File Structure

The project is organized as follows:

    testcases/          # Folder where input and output files are kept
    
    compiling_results   # All the output files results from running the project 
    
    src/                # Folder where the source code files are kept
        IOHandler           # Folder with C code responsible for the input/output file handling
        RulesFiles          # Flex and bison files for the input file parsing [main]
        SymbolTable         # Folder of symbol and symboltable data structures
        symanticAnalysis    # Folder contains SymanticAnalyser class that validates the input file
        QuadGenerator       # The quadruples generator

    makefile            # Makefile for building the project
    gui.py              # Simple ide to write and compile code for using our project 
    README.md           # This file


# Contributers

- [Youssef Ismail](https://github.com/YoussefIsmail1337)
- [Habiba Hassan](https://github.com/HabibaHassan02)
- [Yasmiine Zaki](https://github.com/yasmiinezaki)
- [Ahmed Maher](https://github.com/AhmedMaher309)


## To contribute to GNC language and Compiler, follow these steps:

1. Fork this repository.
2. Make your changes and commit them to your fork.
3. Submit a pull request with a clear description of your changes.
4. congratulations

We welcome any type of contribution, including bug fixes, feature enhancements, code refactoring, and documentation improvements.

# License

GNC Compiler is released under the GPL (GNU General Public License) v3.0 License. Feel free to use the code as you see fit.
