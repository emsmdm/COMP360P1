#include <iostream>
#include <fstream>
#include <cwctype>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool keywordCheck(string s)
{
    if(s == "void" || s == "float" || s == "int" || s == "double" || s == "string" || s == "bool" || s == "char")
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

bool leftBrace(string ch){
    if (ch == "{" || ch == "("){
        return true;
    }
    return false;
}

bool rightBrace(string ch){
    if (ch == "}" || ch == ")"){
        return true;
    }
    return false;
}

bool eq(string ch){
    if (ch == "="){
        return true;
    }
    return false;
}

bool semicolon(string ch){
    if (ch == ";"){
        return true;
    }
    return false;
}

bool plusop(string ch){
    if(ch == "+")
    {
        return true;
    }
    return false;
}

bool minusop(string ch){
    if(ch == "-")
    {
        return true;
    }
    return false;
}
vector<string> tokenSeparation(string filename) {
  ifstream myFile(filename);
  if (!myFile.is_open())
  {
    cout << "Error opening file " << filename << endl;
    return vector<string>();
  }

  string line;
  vector<string> tokens;

  while (getline(myFile, line))
  {
    bool inToken = false;
    string token;

    for (int i = 0; i < line.length(); i++)
    {
      if (isalnum(line[i]))
      {
        if (!inToken)
        {
          token.clear();
          inToken = true;
        }
        token += line[i];
      }
      else
      {
        if (inToken)
        {
          tokens.push_back(token);
          inToken = false;
        }
        tokens.push_back(string(1, line[i]));
      }
    }

    if (inToken)
    {
      tokens.push_back(token);
    }
  }

  myFile.close();

  for (int i = 0; i < tokens.size(); i++)
  {
    if (tokens[i] == " " || tokens[i] == "\n")
    {
      tokens.erase(tokens.begin() + i);
      i--;
    }
  }

  return tokens;
}

/*bool isProgram(vector <string> vec){
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
}*/

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

void analyze(vector <string> vec)
{
    for(string token : vec)
    {
        if(keywordCheck(token))
        {
            cout << "keyword     " << token << endl;
        }
        else if(identCheck(token))
        {
            cout << "ident     " << token << endl;
        }
        else if(leftBrace(token))
        {
            cout << "l_brace     " << token << endl;
        }
        else if(rightBrace(token))
        {
            cout << "r_brace     " << token << endl;
        }
        else if(eq(token))
        {
            cout << "eq          " << token << endl;
        }
        else if(semicolon(token))
        {
            cout << "semicolon   " << token << endl;
        }
        else if(plusop(token))
        {
            cout << "plus_op     " << token << endl;
        }
        else if(minusop(token))
        {
            cout << "minus_op    " << token << endl;
        }
    }
}

int main()
{
    string filename = "TryProgram1.txt";
    vector<string> tokens = tokenSeparation(filename);

    /*for (int i = 0; i < words.size(); i++) 
    {
        cout << words[i] << endl;
    }
    cout << endl;*/
    analyze(tokens);

    
}