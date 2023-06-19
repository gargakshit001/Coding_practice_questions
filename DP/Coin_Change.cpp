/*
Given an integer  array coins[ ] of size N representing different denominations of currency
and an integer sum, find the number of ways you can make sum by using
different combinations from coins[ ].
Note: Assume that you have an infinite supply of each type of coin.
*/

#include<bits/stdc++.h>
using namespace std;

long long int coinChange(int arr[], int n, int sum)
{
  long long int ans[sum + 1];
  memset(ans, 0, sizeof(ans));
  ans[0] = 1;

  for(int i = 0; i < n; i++)
  {
    for(int j = arr[i]; j <= sum; j++)
    {
      ans[j] += ans[j - arr[i]];
    }
  }
  return ans[sum];
}

int main()
{
  int arr[] = {2, 3, 5, 7};
  int n = sizeof(arr)/sizeof(arr[0]);

  int sum = 10;

  cout<<coinChange(arr, n, sum);

  return 0;
}
