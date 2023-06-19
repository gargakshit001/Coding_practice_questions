/*
Given an integer  array coins[ ] of size N representing different denominations
of currency and an integer sum, find the number of ways you can make sum by using
different permutations from coins[ ].
Note: Assume that you have an infinite supply of each type of coin.
*/

#include<bits/stdc++.h>
using namespace std;

int coinChangeCount(int coins[], int n, int sum)
{
  int ans[sum + 1];
  memset(ans, 0, sizeof(ans));
  ans[0] = 1;

  for(int amount = 1; amount <= sum; amount++)
  {
    for(int coin = 0; coin < n; coin++)
    {
      if(amount >= coins[coin])
      {
        //int rem = amount - coin;
        ans[amount] += ans[amount - coins[coin]];
      }
    }
  }

  return ans[sum];
}

int main()
{
  int arr[] = {2, 3, 5, 6};
  int n = sizeof(arr)/sizeof(arr[0]);

  int sum = 10;

  cout<<coinChangeCount(arr, n, sum);

  return 0;
}
