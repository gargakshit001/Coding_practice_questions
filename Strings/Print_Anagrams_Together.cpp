#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> Anagrams(vector<string>& a)
{
  map<string, vector<string>> m;

  for(int i = 0; i < a.size(); i++)
  {
    string s = a[i];
    sort(s.begin(), s.end());
    m[s].push_back(a[i]);
  }

  vector<vector<string>> ans;
  int index = 0;
  for(auto x : m)
  {
    auto v = x.second;

    for(int i = 0; i < v.size(); i++)
    {
      ans[index].push_back(v[i]);
    }
    index++;
  }
  return ans;
}

int main()
{
  vector<string> words{"may", "student", "students", "dog",
                 "studentssess", "god", "cat", "act", "tab",
                 "bat", "flow", "wolf", "lambs", "amy", "yam",
                 "balms", "looped", "poodle"
                  };

  vector<vector<string>> ans = Anagrams(words);
  for(int i = 0; i < ans.size(); i++)
  {
    cout<<ans.at(i)<<endl;
  }

  return 0;
}
