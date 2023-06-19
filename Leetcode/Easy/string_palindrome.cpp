#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

/*bool isPalindrome(string s)
{
  string ans = "";

  if(s == " ")
  {
    return true;
  }

  for(int i = 0; i < s.length(); i++)
  {
    if(s[i] == ',' || s[i] == ':')
    {
      continue;
    }
    else if(s[i] == ' ')
    {
      continue;
    }
    else
    {
      ans.push_back(s[i]);
    }
  }

  transform(ans.begin(), ans.end(), ans.begin(), :: tolower);

  if(ans == " ")
  {
    return true;
  }

  for(int i = 0; i < ans.length() / 2; i++)
  {
    if(ans[i] != ans[ans.length() - 1 - i])
    {
      return false;
    }
  }

  return true;
}*/

bool isPalindrome(string s)
{
  string ans = "";
  if(s == " ")
  {
    return true;
  }

  for(int i = 0; i < s.length(); i++)
  {
    if(isalnum(s[i]))
    {
      ans.push_back(tolower(s[i]));
    }
  }

  if(ans == " ")
  {
    return true;
  }

  for(int i = 0; i < ans.length() / 2; i++)
  {
    if(ans[i] != ans[ans.length() - 1 - i])
    {
      return false;
    }
  }
  return true;
}

int main()
{
  string input = "A man, a plan, a canal: Panama";
  string input2 = "race a car";

  bool output1 = isPalindrome(input);
  bool output2 = isPalindrome(input2);
  cout<<output1<<endl<<output2;
}
