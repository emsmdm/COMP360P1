#include <iostream>
#include <fstream>
#include <cwctype>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int num = -1;

// function for checking keywords
bool keywordCheck(string s)
{
    if(s == "void" || s == "float" || s == "int" || s == "double" || s == "string" || s == "bool" || s == "char")
    {
        return true;
    }
    return false;
}

// function for checking identifiers
bool identCheck(string s)
{
    if(isdigit(s[0]))
    {
        return false;
    }
    return true;
}

// functions for checking left and right braces
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

// function for checking equals
bool eq(string ch){
    if (ch == "="){
        return true;
    }
    return false;
}

// function for checking semicolons
bool semicolon(string ch){
    if (ch == ";"){
        return true;
    }
    return false;
}

// functions for checking plus and minus operators
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

// function for separating each token from try program
vector<string> tokenSeparation(string filename) {
  
  //opens file and checks for errors
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
    
    // logic for separating special characters from other tokens in program
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

  // removes spaces from token vector
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

//utilzes getToken() function to check if a program is present
bool isProgram(string token){
    if(keywordCheck(token)){
        if(identCheck(getToken())){
            if(leftBrace(getToken())){
                if(keywordCheck(getToken())){
                    if(identCheck(getToken())){
                        if(rightBrace(getToken())){
                            if(leftBrace(getToken())){
                                if(isDeclaration(getToken())){
                                    if(isAssignment(getToken())){
                                        if(rightBrace(getToken())){
                                            return true;
                                        }
                                        return false;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    return false;
}


// gets next token for parsing
string getToken()
{
    num++;
    vector <string> vec = tokenSeparation("TryProgram1.txt");
    return vec[num];
}

//utilzes getToken() function to check if an expression is present
bool isExpression(string token){
    if(identCheck(token)){
        string temp = getToken();
        if(plusop(temp) || minusop(temp)){
            isExpression(temp);
        }else{
            num--;
            return true;
        }
        return false;
    }
    return false;
}


//utilzes getToken() function to check if a declaration is present
bool isDeclaration(string token){
    if(keywordCheck(token))
    {
        if((identCheck(getToken())))
        {
            if(semicolon(getToken()))
            {
                string temp = getToken();
                if(keywordCheck(temp))
                {
                    // recursive declaration call for the or condition
                    isDeclaration(temp);
                }
                else
                {
                    num--;
                    return true;
                }
            }
            return false;
        }
        return false;
    }

    return false;
}

//utilzes getToken() function to check if an assign is present
bool isAssignment(string token){
    if(identCheck(token)){
        if(eq(getToken())){
            if(isExpression(getToken())){
                if(semicolon(getToken())){
                    return true;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    return false;
}


// lexical analyzer
void analyze(vector <string> vec)
{
    for(string token : vec)
    {
        if(keywordCheck(token))
        {
            cout << "keyword   " << token << endl;
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
    ifstream MyFile(filename);
    int counter = 0;

    for(int i = 0; i < tokens.size(); i++)
    {
        if(tokens[i] == "float")
        {
            counter++;
        }
    }
    counter--;
    analyze(tokens);

    
}