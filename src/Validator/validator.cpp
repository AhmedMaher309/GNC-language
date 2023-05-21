#include <iostream>
#include <string>
#include <algorithm>
#include "validator.h"

using namespace std;

// cast float to integer
string Validator ::toInt(string value)
{
    for (int i = 1; i < value.length() - 1; i++)
    {
        if (i == 0 && value[i] == '-')
            continue;
        else if (!isdigit(value[i]))
        {
            return value.substr(0, i);
        }
    }
    return value;
}
bool Validator ::isInt(string value)
{
    bool isInteger = 1;
    for (int i = 0; i < value.length(); i++)
    {
        if (i == 0 && value[i] == '-')
            continue;
        else if (!isdigit(value[i]))
        {
            isInteger = 0;
            break;
        }
    }
    return isInteger;
}

bool Validator::isFloat(string value)
{
    bool isfloat = 0;
    bool isnum = 1;
    for (int i = 0; i < value.length(); i++)
    {
        if (value[i] == '.')
        {
            isfloat = 1;
            value.erase(remove(value.begin(), value.end(), '.'), value.end());
            break;
        }
    }
    for (int i = 0; i < value.length(); i++)
    {
        if (!isdigit(value[i]) && !(i == 0 && value[i] == '-'))
        {
            isnum = 0;
            break;
        }
    }
    return (isnum && isfloat);
}

bool Validator::checkString(string value)
{
    if (value[0] == '"' && value[value.length() - 1] == '"')
        return 1;
    else
        return 0;
}

bool Validator::checkChar(string value)
{
    if (value[0] == '\'' && value[value.length() - 1] == '\'' && value.length() == 3)
        return 1;
    else
        return 0;
}

string Validator ::TypeConversion(string type1, string type2, string value)
{
    if (type1 == "int" && type2 == "float" && isFloat(value))
    {
       return toInt(value);
    }
    return value;
}

// return flase if there is type mismatch and push the error to the errorlist, otherwise return true
bool Validator::checkType(string type1, string type2)
{
    if (type1 != type2 && !(type1 == "float" && type2 == "int") && !(type1 == "int" && type2 == "float"))
    {
        return false;
    }
    return true;
}

bool Validator::isConstant(bool isinitialised, bool isconstant)
{
    if (isinitialised && isconstant)
        return 1;
    else
        return 0;
}


// check if the variable is initialized or raise warning
void Validator::checkIntializedVariable(bool isinitialised, int lineNumber){
    if (! isinitialised){
        raiseWarning("variable is not intialized", lineNumber);
    }
}

void Validator::raiseError(std::string message, int lineNumber){
        string error = "Error in line [" + std::to_string(lineNumber) + "]: " + message ;
        this->errorList.push_back(error);
}

void Validator::raiseWarning(std::string message, int lineNumber){
        string error = "Warning in line [" + std::to_string(lineNumber) + "]: " + message ;
        this->errorList.push_back(error);
}

void Validator:: printErrorList(){
    for(int i = 0; i < this->errorList.size();i++){
        cout << this->errorList[i]<<endl;
    }
}

void Validator:: printWarningList(){
    for(int i = 0; i < this->warningList.size();i++){
        cout << this->warningList[i]<<endl;
    }
}
