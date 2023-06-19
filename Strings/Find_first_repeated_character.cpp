#include<bits/stdc++.h>
#include<iostream>
using namespace std;

char firstRepeating(string &str)
{
  map<char, int> mp;
  mp[str[0]]++;
  for(int i = 1; i < str.length(); i++)
  {
    if(mp.find(str[i]) != mp.end())
    {
      cout<<i<<endl;
      return str[i];
    }
    else
    {
      mp[str[i]]++;
    }
  }
  return 0;
}

int main()
{
  string str = "hello geeks";

  cout<<firstRepeating(str);

  return 0;
}
