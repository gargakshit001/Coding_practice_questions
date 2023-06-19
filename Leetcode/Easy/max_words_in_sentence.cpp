#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<string>
using namespace std;

//Time Complexity: O(m*n); Space Complexity : O(n)
int mostWordsFound(vector<string>& sentences)
{
  int n = sentences.size();
  int counter, ans = 0;
  for(int i = 0; i < n; i++)
  {
    int k = sentences[i].length();
    counter = 1;
    for(int j = 0; j < k; j++)
    {
      if(sentences[i][j] == ' ')
      {
        counter++;
      }
    }
    ans = max(ans, counter);
  }
  return ans;
}

//Time Complexity: O(m*n); Space Complexity : O(1)
int mostWordsFound1(vector<string>& sentences)
{
  int res = 0;
  for(auto const & s : sentences)
  {
    int n = count(s.begin(), s.end(), ' ');
    res = max(res, n + 1);
  }
  return res;
}

int main()
{
  vector<string> sentences = {"alice and bob love leetcode", "i think so too", "this is great thanks very much"};
  /*{
    {"alice and bob love leetcode"},
    {"i think so too"},
    {"this is great thanks very much}"
  };*/

  int mostwords = mostWordsFound1(sentences);
  cout<<mostwords;

  return 0;
}
