#include<iostream>
#include<string>
#include<vector>
using namespace std;

int maximumWealth(vector<vector<int>>& accounts)
{
  int res = 0;
  for(int i= 0; i < accounts.size(); i++)
  {
    int temp = 0;
    for(int j = 0; j < accounts[i].size(); j++)
    {
      temp += accounts[i][j];
    }
    res = max(temp, res);
  }
  return res;
}

int main()
{
  vector<vector<int>> accounts
  {
    {1, 2, 3},
    {1, 2, 3},
    {3, 5, 2}
  };

  int maxValue = maximumWealth(accounts);
  cout<<maxValue;

  return 0;
}
