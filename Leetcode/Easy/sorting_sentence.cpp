#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;

string sortSentence(string s)
{
  string word = "";
  vector<string> v(10);

  for(int i = 0; i < s.length(); i++)
  {
    if(s[i] >= '0' && s[i] <= '9')
    {
      v[s[i] - '0'] = word + " ";
      word = "";
      i++;
    }
    else
    {
      word += s[i];
    }
  }

  for(string x : v)
  {
    word += x;
  }

  word.pop_back();

  return word;
}

int main()
{
  string input = "Myself2 Me1 I4 and3";

  string output = sortSentence(input);
  cout<<output;

  return 0;
}
