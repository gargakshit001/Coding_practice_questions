#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void printAllSubstrings(string str, int n)
{
  for(int i = 0; i < n; i++)
  {
    string substr;
    for(int j = i; j < n; j++)
    {
      substr += str[j];
      cout<<substr<<endl;
    }
  }
}

int main()
{
  string str = "Geeky";
  printAllSubstrings(str, str.length());

  return 0;
}
