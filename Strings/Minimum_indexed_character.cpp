/*Given a string str and another string patt. Find the character
in patt that is present at the minimum index in str*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int minIndexChar(string str, string patt)
{
  unordered_map<char, int> mp;

  for(int i = 0; i < str.length(); i++)
  {
    if(mp.find(str[i]) != mp.end())
    {
      continue;
    }
    else
    {
      mp[str[i]] = i;
    }
  }

  int i = 0, ans = INT_MAX;
  while(i < patt.length())
  {
    if(mp.find(patt[i]) != mp.end())
    {
      ans = min(ans, mp[patt[i]]);
      //if found
    }
    i++;
  }

  if(ans == INT_MAX)
  {
    return -1;
  }
  return ans;
}

int main()
{
  string str = "geeksforgeeks";
  string patt = "fks";

  int ans = minIndexChar(str, patt);
  cout<<ans;

  return 0;
}
