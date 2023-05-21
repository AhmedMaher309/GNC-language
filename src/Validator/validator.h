#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Validator
{
private:
    vector<string> errorList;
    vector<string> warningList;

public:
    /*
    // Summary:
    //     Request extensions.
    public static class RequestExtensions
    {
        private static readonly char[] _commaSeparators = new char[1] { ',' };

        private static readonly char[] _keyValueSeparators = new char[1] { '=' };

        //
        // Summary:
        //     Tries the get location.
        //
        // Parameters:
        //   request:
        //     The request.
        //
        //   geolocation:
        //     The geolocation.
        publ
    */
    string toInt(string value);
    bool isInt(string value);
    bool isFloat(string value);
    bool checkString(string value);
    bool checkChar(string value);
    string TypeConversion(string type1, string type2, string value);
    bool isConstant(bool isinitialised, bool isconstant);
    bool checkType(string type1, string type2, int lineNumber);
    void checkIntializedVariable(bool isinitialised, int lineNumber);
    void printErrorList();
    void printWarningList();

};