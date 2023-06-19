#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int nth_ugly_num(int n)
{
  int c2(0), c3(0), c5(0);
  vector<int> dp(n + 1);

  dp[0] = 1;

  for(int i = 1; i <= n; i++)
  {
    dp[i] = min(2 * dp[c2], min(3 * dp[c3], 5 * dp[c5]));

    if(2 * dp[c2] == dp[i])
    {
      c2++;
    }
    if(3 * dp[c3] == dp[i])
    {
      c3++;
    }
    if(5 * dp[c5] == dp[i])
    {
      c5++;
    }
  }
  return dp[n - 1];
}

int nth_super_ugly_num(int n, int primes[], int k)
{
  vector<int>pointers(k);
  for(int i = 0; i < k; i++)
  {
    pointers[i] = 0;
  }

  vector<int> dp(n + 1);
  dp[0] = 1;

  for(int i = 1; i <= n; i++)
  {
    int product = INT_MAX;
    for(int j = 0; j < k; j++)
    {
      product = min(product, dp[pointers[j]] * primes[j]);
    }
    dp[i] = product;

    for(int a = 0; a < k; a++)
    {
      if(dp[pointers[a]] * primes[a] == dp[i])
      {
        pointers[a]++;
        continue;
      }
    }
  }

  return dp[n - 1];
}

int main()
{
  int n;
  cin>>n;

  int primes[] = {2, 3, 5};
  int ps = sizeof(primes) / sizeof(primes[0]);
  cout<<"Super Ugly Number: "<<nth_super_ugly_num(n, primes, ps)<<endl;
  cout<<"Ugly Number: "<<nth_ugly_num(n);

  return 0;
}
