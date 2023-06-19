#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int maxLen(vector<int>&arr, int n)
{
  unordered_map<int, int> map;
  int maxLen = 0;
  int sum = 0;

  for(int i = 0; i < n; i++)
  {
    sum += arr[i];
    if(sum == 0)
    {
      maxLen = max(maxLen, i + 1);
    }
    else
    {
      if(map.find(sum) != map.end())
      {
        maxLen = max(maxLen, i - map[sum]);
      }
      else
      {
        map[sum] = i;
      }
    }
  }

  return maxLen;
}

int main()
{
  vector<int> arr = {1, 0, 3};
  vector<int> arr1 = {15, -2, 2, -8, 1, 7, 10, 23};

  cout<<maxLen(arr1, arr1.size());
  //cout<<ans<<endl;

  return 0;
}
