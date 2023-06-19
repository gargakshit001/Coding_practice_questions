#include<bits/stdc++.h>
#include<iostream>
using namespace std;

string UncommonChars(string str1, string str2)
{
  string ans = "", res = "-1";

  unordered_map<char, int> mp1, mp2;

  for(int i = 0; i < str1.length(); i++)
  {
    mp1[str1[i] - 'a'] = 1;
  }
  for(int i = 0; i < str2.length(); i++)
  {
    mp2[str2[i] - 'a'] = 1;
  }

  for(int i = 0; i < 26; i++)
  {
    if(mp1[i] ^ mp2[i])
    {
      ans += char(i + 'a');
    }
  }

  if(ans == "")
  {
    return res;
  }
  return ans;
}

int main()
{
  string a = "geeksforgeeks";
  string b = "geeksquiz";
  string result = UncommonChars(a,b);
  cout << result << endl;

  return 0;
}
