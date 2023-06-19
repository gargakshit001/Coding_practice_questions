#include<bits/stdc++.h>
#include<iostream>
using namespace std;

string rremove(string s)
{
  string ans = "";
  int n = s.length();
  int i = 0;

  while(i < n)
  {
    char c = s[i];
    int frequency = 0;
    while(s[i] == c)
    {
      frequency++, i++;
    }
    if(frequency == 1)
    {
      ans += c;
    }
  }

  if(ans == s)
  {
    return ans;
  }
  return rremove(ans);
}

int main()
{
  string str = "GeeksforGeeks";

  cout<<rremove(str);

  return 0;
}
