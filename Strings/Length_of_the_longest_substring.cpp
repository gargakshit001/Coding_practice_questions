#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//TLE
int longestUniqueSubsttr(string str)
{
  unordered_map<char, int> mp;
  int index = 0, maxCount = 0;

  for(int i = 0; i < str.length(); i++)
  {
    if(mp.find(str[i]) != mp.end())
    {
      index = max(index, mp[str[i]] + 1);
    }
    mp[str[i]] = i;
    maxCount = max(maxCount, i - index + 1);
  }

  return maxCount;
}

int longestUniqueSubsttr_better(string str)
{
  int i = 0, j = 0, maxCount = INT_MIN;
  int m[26] = {0};

  while(j < str.length())
  {
    m[str[j] - 'a']++;
    if(m[str[j] - 'a'] > 1)
    {
      while(m[str[j] - 'a'] > 1)
      {
        m[str[i] - 'a']--;
        i++;
      }
    }
    maxCount = max(maxCount, j - i + 1);
    j++;
  }

  return maxCount;
}

int main()
{
  string s = "abcdhcbayr";

  int ans1 = longestUniqueSubsttr(s);
  int ans2 = longestUniqueSubsttr_better(s);
  cout<<ans1<<endl<<ans2;
}
