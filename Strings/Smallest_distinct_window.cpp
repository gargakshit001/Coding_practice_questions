#include<bits/stdc++.h>
using namespace std;

int findSubString(string str)
{
  set<char> s;
  for(char c : str)
  {
    s.insert(c);
  }

  unordered_map<char, int> map;

  int ans = str.size(); //in case the string is made up of unique characters
  int n = s.size();
  int i = 0;
  int j = 0;

  while(i < str.size())
  {
    map[str[i]]++;
    if(map.size() == n)
    {
      while(map[str[j]] > 1)
      {
        map[str[j]]--;
        j++;
      }
      ans = min(ans, i - j + 1); //to store the min value of substring containing unique characters
    }
    i++;
  }
  return ans;
}

int main()
{
  string str = "aabcbcdbca";
  cout << "Smallest window containing all distinct characters is: "<< findSubString(str);

  return 0;
}
