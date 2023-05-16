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
    bool isInt(string value);
    bool checkFloat(string value);
    bool checkString(string value);
    bool checkChar(string value);
    bool checkSyntax(string type, string value);
    bool isConstant(bool isinitialised, bool isconstant);
    // void addtoErrorList(int error_line, string var_name);
    // void printErrorList();
};