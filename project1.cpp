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
    int counter;

    while(getline(MyFile, text, ' '))
    {
        lexemes.push_back(text);
    }
    MyFile.close();
    
    vector<char> non_alphabetic_characters;

    for (auto token : lexemes)
    {
        for (char ch : token) 
        {
            if (ch < 'A' || ch > 'Z' && ch < 'a' || ch > 'z') 
            {
                //cout << ch << endl;
                non_alphabetic_characters.push_back(ch);
            }
        }
    }

  for (auto ch : non_alphabetic_characters) {
    string temp;
    temp += ch;
    lexemes.push_back(temp);
  }

  

    
    

    for(int i = 0; i < lexemes.size(); i++)
    {
        cout << lexemes.at(i)<<endl;
    }
    //cout<<iswalnum(';');
    //cout<<lexemes.at(1).at(0);
    
}