#include <iostream>
#include <string>
#include <unordered_map>

#include "symbol.h"
using namespace std;

enum type{
 INT,
 FLOAT,
 CHAR,
 BOOL,
 STRING
};

struct symbol
{
 string varName;
 enum type varType;
 string value;
 bool declareFlag;
 void* memoryLocation;
 
};

void testFunc()
{
symbol* mySymbol = new symbol;
mySymbol->memoryLocation = &mySymbol;
mySymbol->varName = "myVariable";
mySymbol->varType = INT;
mySymbol->declareFlag = true;
mySymbol->value = "123";
unordered_map<int,int> map;
map[1] = 150;
cout<<endl;
cout<<"this is a test to check if the function is working"<<endl;
cout<<"the location of the symbol is "<<mySymbol->memoryLocation<<endl;
cout<<"the variable name is "<<mySymbol->varName<<endl;
cout<<"the variable type is "<<mySymbol->varType<<endl;
cout<<"the declare flag is "<<mySymbol->declareFlag<<endl;
cout<<"the value is "<<mySymbol->value<<endl;
cout<<endl;
cout<<"and here is a print for a value in the unordered_map "<<map[1]<<endl;

}

