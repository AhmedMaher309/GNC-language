#include <iostream>
#include <string>
#include <algorithm>
#include "validator.h"

using namespace std;

// TODO: handle -ve value
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
bool Validator::checkFloat(string value)
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
    if (type1 == "int" && type2 == "float" && checkFloat(value))
    {
        return toInt(value);
    }
    return value;
}

bool Validator::checkType(string type1, string type2, int lineNumber)
{
    if (type1 != type2 && !(type1 == "float" && type2 == "int") && !(type1 == "int" && type2 == "float"))
    {
        printf("Error [%d]: Type mismatch\n", lineNumber);
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
