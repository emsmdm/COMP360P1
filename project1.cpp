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