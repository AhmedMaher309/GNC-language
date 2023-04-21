# JSPL (just a simple programming language)

This is a simple programming language using flex and bison tools 

## Getting Started

Clone the repository to your local machine

    https://github.com/AhmedMaher309/Programming-language.git


Install Flex and Bison if they are not already installed. They can be installed on Ubuntu distro using the following commands:
    
    sudo apt install flex
    sudo apt install bison

install gcc compilers if not already installed on your machine using the following commands:
    
    sudo apt install build-essential
    sudo apt-get install manpages-dev

Navigate to the source directory and run the project using the following commands:

    flex lexer.l
    gcc lex.yy.c -lfl -o out
    ./out


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

    src/
        lexer.l        # Flex lexer file
        parser.y       # Bison parser file
        Makefile       # Makefile for building the project
    README.md          # This file

