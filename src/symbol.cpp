#include <iostream>
#include <string>
#include <unordered_map>
#include <iomanip>

#include "symbol.h"
using namespace std;
    struct symbol {
    char* name;
    char* varType;
    char* value = "0xgarbage";
    bool isDeclared = false;
    };

/* ////////////////////////////////symbol struct utilites///////////////////////////////////////////*/
    void printSymbolData(symbol * symbol){
        cout << symbol->name << " " << symbol->varType << " " << symbol->value << endl;
        cout<< "memory is " << symbol<< endl;
    }

    symbol * createSymbol(char* name, char* varType){
           symbol *sym = new symbol;
           sym->varType = varType;
           sym->name = name;
           return sym;
    }
    
    void setValue(char * value, symbol * sym){
        sym->value = value;
        sym->isDeclared = true;
    }

    char * getValue(symbol * sym){
        return sym->value;
    }
    
    // void markAsDeclared(symbol * sym){
    //     sym->isDeclared = true;
    // }





/* ///////////////////////////////symbol table////////////////////////////////////////////*/

unordered_map<string, symbol*> symbolTable;
void addSymbol(char* key, symbol* value){
    symbolTable[key] = value;
}

void printSymbolByKey( char* keystr){
    symbol* value = symbolTable[keystr];
    cout << keystr << " " << value->name << " " << value->varType << " " << value->value << endl;
}

void modifySymbolInTable(char* key, char* modification){
    symbol* symbol = symbolTable[key];
    setValue(modification, symbol);
}

void printSymbolTable(){
    cout << left << setw(20) << "variable name" << setw(20) << "variable type" << setw(20) << "variable value" << setw(15) << "is declared" << setw(20) << "memory location" << endl;
    for (auto x : symbolTable) {
        cout << left << setw(20) << x.first << setw(20) << x.second->varType << setw(20) << x.second->value << setw(15) << x.second->isDeclared << setw(20) << x.second << endl;
    }
    cout << endl << endl;
}

