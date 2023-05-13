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
pair<bool, bool> Validator::checkFloat(string value)
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
    return make_pair(isnum, isfloat);
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
    if (!isinitialised)
        return 1;

    bool isInteger = isInt(value);
    if (type == "int")
        return isInteger;
    if (type == "bool")
    {
        if (isInteger && (value == "1" || value == "0"))
            return 1;
        else
            return 0;
    }
    if (type == "float")
    {
        pair<bool, bool> ret = checkFloat(value);
        if (ret.first && ret.second)
            return 1;
        else
            return 0;
    }
    if (type == "string")
        return checkString(value);

    if (type == "char")
        return checkChar(value);
    return 0;
}

bool Validator::check_constant(bool isinitialised, bool isconstant)
{
    if (isinitialised && isconstant)
        return 1;
    else
        return 0;
}
