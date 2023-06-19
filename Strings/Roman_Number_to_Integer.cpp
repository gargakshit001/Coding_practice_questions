#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int value(char ch)
{
  if(ch == 'I')
  {
    return 1;
  }
  if(ch == 'V')
  {
    return 5;
  }
  if(ch == 'X')
  {
    return 10;
  }
  if(ch == 'L')
  {
    return 50;
  }
  if(ch == 'C')
  {
    return 100;
  }
  if(ch == 'D')
  {
    return 500;
  }
  if(ch == 'M')
  {
    return 1000;
  }

  return -1;
}

int romanToDecimal(string& str)
{
  int ans = 0;
  for(int i = 0; i < str.length(); i++)
  {
    int s1 = value(str[i]);

    if(i + 1 < str.length())
    {
      int s2 = value(str[i + 1]);

      if(s2 > s1)
      {
        ans += s2 - s1;
        i++;
      }
      else
      {
        ans += s1;
      }
    }
    else
    {
      ans += s1;
    }
  }

  return ans;
}

int main()
{
  string s = "MCMIV";
  cout<<romanToDecimal(s);

  return 0;
}
