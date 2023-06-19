#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

bool isIsomorphicHelper(string a, string b)
{
  unordered_map<char, char> mp;

  for(int i = 0; i < a.length(); i++)
  {
    if(mp.find(a[i]) != mp.end())
    {
      if(mp[a[i]] != b[i])
      {
        return false;
      }
    }
    else
    {
      mp[a[i]] = b[i];
    }
  }
  return true;
}

bool isIsomorphic(string s, string t)
{
  return isIsomorphicHelper(s, t) && isIsomorphicHelper(t, s);
}

int main()
{
  string a = "cvcv";
  string b = "baba";

  bool output = isIsomorphic(a, b);
  cout<<output;
}
