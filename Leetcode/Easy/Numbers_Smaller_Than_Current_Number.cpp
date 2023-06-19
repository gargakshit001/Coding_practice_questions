#include <bits/stdc++.h>
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> smallerNumbersThanCurrent(vector<int>& nums)
{
  map <int, int> mp;

  int n = nums.size();

  vector<int> snum = nums;

  sort(snum.begin(), snum.end());

  for(int i = n - 1; i >= 0; i--)
  {
    mp[snum[i]] = i;
  }

  for(int i = 0; i < n; i++)
  {
    nums[i] = mp[nums[i]];
  }

  return nums;
}

int main()
{
  vector<int> input = {6,5,4,8};
  vector<int> output = smallerNumbersThanCurrent(input);

  for(int i = 0; i < input.size(); i++)
  {
    cout<<output.at(i)<<" ";
  }

  return 0;
}
