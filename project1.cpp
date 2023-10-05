#include <iostream>
#include <fstream>
#include <cwctype>
#include <string>
#include <vector>
#include <algorithm>

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
    if (ch == '{' | ch == '('){
        return true;
    }
    return false;
}

bool rightBrace(char ch){
    if (ch == '}' | ch == ')'){
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
vector<string> wordSeparation(string filename) {
  ifstream myFile(filename);
  if (!myFile.is_open())
  {
    cout << "Error opening file " << filename << endl;
    return vector<string>();
  }

  string line;
  vector<string> words;

  while (getline(myFile, line))
  {
    bool in_word = false;
    string word;

    for (int i = 0; i < line.length(); i++)
    {
      if (isalnum(line[i]))
      {
        if (!in_word)
        {
          word.clear();
          in_word = true;
        }
        word += line[i];
      }
      else
      {
        if (in_word)
        {
          words.push_back(word);
          in_word = false;
        }
        words.push_back(string(1, line[i]));
      }
    }

    if (in_word)
    {
      words.push_back(word);
    }
  }

  myFile.close();

  for (int i = 0; i < words.size(); i++)
  {
    if (words[i] == " " || words[i] == "\n")
    {
      words.erase(words.begin() + i);
      i--;
    }
  }

  return words;
}

bool isProgram(){
    if(isKeyword()){
        if(isIdent()){
            if(leftBrace(lexemes[i]) == true){
                if(isKeyword()){
                    if(isIdent()){
                        if(rightBrace(lexemes[i]) == true){
                            if(leftBrace(lexemes[i]) == true){
                                if(isDeclaration()){
                                    if(isAssignment()){
                                        if(rightBrace(lexemes[i]) == true){
                                            return "The try program is generated by BNF  grammar for Try Program";
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

bool isDeclaration(){

}

bool isAssignment(){

}

bool isExpression(){

}

bool isKeyword(){

}

bool isIdent(){

}

int main()
{
    string filename = "TryProgram1.txt";
    vector<string> words = wordSeparation(filename);

    for (int i = 0; i < words.size(); i++) 
    {
        cout << words[i] << endl;
    }
    cout << endl;
    
}