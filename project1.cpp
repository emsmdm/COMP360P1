#include <iostream>
#include <fstream>
#include <cwctype>

using namespace std;

int main()
{
    ifstream MyFile("TryProgram1.txt");
    string text;

    while(getline(MyFile, text))
    {
        cout << text << endl;
    }

    MyFile.close();
}

bool leftBrace(char ch){
    if (ch == '{'){
        return true;
    }
    return false
}

bool rightBrace(char ch){
    if (ch == '}'){
        return true;
    }
    return false
}

bool eq(char ch){
    if (ch == '='){
        return true;
    }
    return false
}

bool semicolon(char ch){
    if (ch == ';'){
        return true;
    }
    return false
}