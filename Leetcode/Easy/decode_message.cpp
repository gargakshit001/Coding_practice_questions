#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<unordered_map>
using namespace std;

string decodeMessage(string key, string message)
{
  string alphabets, ans;
  unordered_map<char, char> mp;

  for(char i = 'a'; i <= 'z'; i++)
  {
    alphabets.push_back(i);
  }

  int j = 0;
  for(int i = 0; i < key.length(); i++)
  {
    if(key[i] == ' ')
    {
      continue;
    }
    if(mp.find(key[i]) == mp.end())
    {
      mp[key[i]] = alphabets[j];
      j++;
    }
  }

  for(int i = 0; i < message.length(); i++)
  {
    if(message[i] == ' ')
    {
      ans.push_back(' ');
    }

    else
    {
      ans.push_back(mp[message[i]]);
    }
  }

  return ans;
}

int main()
{
  string s1 = "eljuxhpwnyrdgtqkviszcfmabo";
  string s2 = "zwx hnfx lqantp mnoeius ycgk vcnjrdb";

  string output = decodeMessage(s1, s2);
  cout<<output;
}
