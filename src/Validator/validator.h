#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Validator
{
private:
    vector<pair<int, string>> err_list;

public:
    string toInt(string value);
    bool checkFloat(string value);
    bool checkString(string value);
    bool checkChar(string value);
    string TypeConversion(string type1, string type2, string value);
    bool isConstant(bool isinitialised, bool isconstant);
    bool checkType(string type1, string type2, int lineNumber);
    // void addtoErrorList(int error_line, string var_name);
    // void printErrorList();
};