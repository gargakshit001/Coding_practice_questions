#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxSum(int arr[], int n)
{
  vector<int> ans;
  int sum = 0;
  for(int i = 0; i < n; i++)
  {
    if(arr[i] < 0)
    {
      sum += arr[i];
    }
    else
    {
      ans.push_back(sum);
      sum = 0;
      ans.push_back(arr[i]);
    }
  }
  ans.push_back(sum);

  int min_ele = *min_element(ans.begin(), ans.end());
  int res = 0;
  for(int i = 0; i < ans.size(); i++)
  {
    if(ans[i] == min_ele)
    {
      continue;
    }
    else
    {
      res += ans[i];
    }
  }
  return res;
}

int maxSum_better(int arr[], int n)
{
  int sum = 0;
  int ans = 0;
  int min_ele = 0;
  for(int i = 0; i < n; i++)
  {
    if(arr[i] > 0)
    {
      sum = sum + arr[i];
      ans = 0;
    }
    else
    {
      sum = sum + arr[i];
      ans = ans + arr[i];
      min_ele = min(min_ele, ans);
    }
  }
  return sum + abs(min_ele);
}

int main()
{
  int a[] = {10, -3, -4, 7, 6, 5, -4, -1};
  int n = sizeof(a) / sizeof(a[0]);

  cout<<maxSum(a, n)<<endl;
  cout<<maxSum_better(a, n)<<endl;

  return 0;
}
