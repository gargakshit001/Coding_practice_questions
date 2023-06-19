#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int lps(string str)
{
  int ls[str.length()] = {0};
  ls[0] = 0;
  int i = 1, len = 0;

  while(i < str.length())
  {
    if(str[i] == str[len])
    {
      len++;
      ls[i] = len;
      i++;
    }
    else
    {
      if(len == 0)
      {
        ls[i] = 0;
        i++;
      }
      else
      {
        len = ls[len - 1];
      }
    }
  }

  return ls[str.length() - 1];
}

int main()
{
  string s = "aabaabaa";

  int ans = lps(s);
  cout<<ans;
}
