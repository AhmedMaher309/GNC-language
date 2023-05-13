#include <iostream>
#include <string>
#include <algorithm>
#include "validator.h"

using namespace std;

bool Validator ::isInt(string value)
{
    bool isInteger = 1;
    for (int i = 0; i < value.length(); i++)
    {
        if (!isdigit(value[i]))
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
        if (!isdigit(value[i]))
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
bool Validator ::checkSyntax(string type, string value)
{
    if (type == "int" && isInt(value))
        return 1;
    else if (type == "bool" && (value == "1" || value == "0"))
        return 1;
    else if (type == "float" && checkFloat(value))
        return 1;
    else if (type == "string" && checkString(value))
        return 1;
    else if (type == "char" && checkChar(value))
        return 1;
    return 0;
}

bool Validator::isConstant(bool isinitialised, bool isconstant)
{
    if (isinitialised && isconstant)
        return 1;
    else
        return 0;
}
