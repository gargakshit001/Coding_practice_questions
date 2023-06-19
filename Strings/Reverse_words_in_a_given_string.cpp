#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void reverse(string str)
{
  stack<char> ans;
  for(int i = str.length() - 1; i >= 0; i--)
  {
    char ch = str[i];
    if(!isalpha(ch))
    {
      while(!ans.empty())
      {
        cout<<ans.top();
        ans.pop();
      }
      cout<<ch;
    }
    else
    {
      ans.push(str[i]);
    }
  }
  while(!ans.empty())
  {
    cout<<ans.top();
    ans.pop();
  }
}

int main()
{
  string str = "pqr.mno";
  cout<<str<<endl;

  reverse(str);

  return 0;
}
