#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int atoi(string str)
{
  int ans = 0, start = 0;
  if(str[0] == '-')
  {
    start = 1;
  }

  while(start < str.length())
  {
    if(isdigit(str[start]))
    {
      ans = ans*10 + (str[start] - '0');
    }
    else
    {
      return -1;
    }
    start++;
  }

  if(str[0] == '-')
  {
    return -ans;
  }

  return ans;
}

int main()
{
  string s = "-12345";

  int ans = atoi(s);
  cout<<ans;
}
