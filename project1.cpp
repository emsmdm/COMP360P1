#include <iostream>
#include <fstream>
#include <cwctype>
#include <string>
#include <vector>

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
    ifstream MyFile("TryProgram1.txt");
    string text;
    vector <string> lexemes;

    while(getline(MyFile, text, ' '))
    {
        lexemes.push_back(text);
    }
    
    MyFile.close();

    /*for(int i = 0; i < lexemes.size(); i++)
    {
        cout << lexemes.at(i)<<endl;
    }*/
    cout<<lexemes.at(1);
    
}