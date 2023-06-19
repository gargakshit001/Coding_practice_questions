#include<bits/stdc++.h>
#include<iostream>
using namespace std;

long long findNth(long long n)
{
  long long ans = 0, t = 1;

  while(n)
  {
    ans = ans + t * (n % 9);
    t = t * 10;
    n = n / 9;
  }

  return ans;
}

int main()
{
  long long n;
  cin>>n;

  cout<<findNth(n);

  return 0;
}
