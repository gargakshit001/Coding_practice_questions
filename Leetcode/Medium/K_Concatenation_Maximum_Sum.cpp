#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

kConcatenationMaxSum(vector<int> &arr, int k)
{
  vector<int> res;
  for(int i = 0; i < k; i++)
  {
    for(int j = 0; j < arr.size(); j++)
    {
      res.push_back(arr.at(j));
    }
  }

  int max_sum = 0;
  int sum = 0;
  int mod = pow(10, 9) + 7;
  for(int i = 0; i < res.size(); i++)
  {
    sum = max(res[i], sum + res[i]);
    max_sum = max(sum, max_sum);
  }
  return max_sum % mod;
}

kConcatenationMaxSum_better(vector<int> &arr, int k)
{
  int max_sum = 0;
  int mod = pow(10, 9) + 7;
  int n = arr.size();
  for(auto i = 0, sum = 0; i < min(2, k) * n; i++)
  {
    sum = max(arr[i % n], sum + arr[i % n]);
    max_sum = max(sum, max_sum);
  }

  int ans = (max_sum + max(0ll, accumulate(arr.begin(), arr.end(), 0ll) * max(0, k - 2))) % mod;
  return ans;
}

int main()
{
  vector<int> arr = {-5,-2,0,0,3,9,-2,-5,4};
  int k = 10000000;
  int ans2 = kConcatenationMaxSum_better(arr, k);
  cout<<ans2<<endl;
  int ans1 = kConcatenationMaxSum(arr, k);
  cout<<ans1<<endl;

  return 0;
}
