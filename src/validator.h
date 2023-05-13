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
    pair<bool, bool> checkFloat(string value);
    bool checkString(string value);
    bool checkChar(string value);
    bool check_syntax(string type, string value, bool isinitialised);
    bool check_constant(bool isinitialised, bool isconstant);
    // void addtoErrorList(int error_line, string var_name);
    // void printErrorList();
};