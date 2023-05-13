#include <iostream>
#include <string>
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
    for (int i = 0; i < value.length(); i++)
    {
        if (value[i] == '.')
        {
            isfloat = 1;
            break;
        }
    }
    return isfloat;
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
bool Validator ::check_syntax(string type, string value, bool isinitialised)
{
    if (! isinitialised)
    {
        return 1;
    }
    bool isInteger = isInt(value);
    if (type == "int")
    {
        return isInteger;
    }
    if (type == "bool")
    {
        if (isInteger && (value == "1" || value == "0"))
            return 1;
        else
            return 0;
    }
    if (type == "float")
        return checkFloat(value);

    if (type == "string")
        return checkString(value);

    if (type == "char")
        return checkChar(value);
    return 0;
}
