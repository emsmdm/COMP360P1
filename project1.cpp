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
vector<string> separate_words_and_special_characters_keeping_words_together(string filename) {
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

int main()
{
    string filename = "TryProgram1.txt";
    vector<string> words = separate_words_and_special_characters_keeping_words_together(filename);

    for (int i = 0; i < words.size(); i++) 
    {
        cout << words[i] << endl;
    }
    cout << endl;
    
}