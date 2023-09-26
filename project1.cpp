#include <iostream>
#include <fstream>
#include <cwctype>

using namespace std;

bool keywordCheck(string s)
{
    if(s == "void" || "float" || "int" || "double" || "string" || "bool" || "char")
    {
        return true;
    }
    return false;
}

bool identCheck(string s)
{
    if(isdigit(s[0]))
    {
        return false;
    }
    return false;
}

bool leftBrace(char ch){
    if (ch == '{'){
        return true;
    }
    return false;
}

bool rightBrace(char ch){
    if (ch == '}'){
        return true;
    }
    return false;
}

bool eq(char ch){
    if (ch == '='){
        return true;
    }
    return false;
}

bool semicolon(char ch){
    if (ch == ';'){
        return true;
    }
    return false;
}

int main()
{
    /* test for file reading
    ifstream MyFile("TryProgram1.txt");
    string text;

    while(getline(MyFile, text))
    {
        cout << text << endl;
    }

    MyFile.close();
    */
}