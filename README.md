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

## Running the project

Build the binary file using the following command:

    make build

To clean up the build artifacts, run the following command:
    
    make clean

**Note:** If you'd like to build without printing all the build information and clean the build artifacts automatically, run the following command:

    make cleanbuild

To run the built binary, run the command:

    make run 

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

    inputs/            # Folder where input files are kept
    outputs/           # Folder where input files are kept
    
    src/               # Folder where the source code files are kept
        iohandler.c         # C code responsible for the input/output file handling
        lexer.l             # Flex lexer file
        parser.y            # Bison parser file

    makefile           # Makefile for building the project
    README.md          # This file


# Contributers

- [Youssef Ismail](https://github.com/YoussefIsmail1337)
- [Habiba Hassan](https://github.com/HabibaHassan02)
- [Yasmiine Zaki](https://github.com/yasmiinezaki)
- [Ahmed Maher](https://github.com/AhmedMaher309)

