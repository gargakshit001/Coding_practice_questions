#include<iostream>
using namespace std;

//brute-force method
int minStepto1(int n)
{
  if(n == 1)
  {
    return 0;
  }

  int x = minStepto1(n - 1);

  int y = INT_MAX;
  int z = INT_MAX;

  if(n % 2 == 0)
  {
    y = minStepto1(n / 2);
  }

  if(n % 3 == 0)
  {
    z = minStepto1(n / 3);
  }

  return 1 + min(x, min(y, z));
}

//Memorization Method
int minStepto1_betterHelper(int n, int* ans)
{
  if(n == 1)
  {
    ans[n] = 0;
    return 0;
  }

  if(ans[n - 1] == -1)
  {
    ans[n - 1] = minStepto1_betterHelper(n - 1, ans);
  }

  int x = INT_MAX;
  int y = INT_MAX;

  if(n % 2 == 0)
  {
    if(ans[n / 2] == -1)
    {
      ans[n / 2] = minStepto1_betterHelper(n / 2, ans);
    }
    x = ans[n / 2];
  }

  if(n % 3 == 0)
  {
    if(ans[n / 3] == -1)
    {
      ans[n / 3] = minStepto1_betterHelper(n / 3, ans);
    }
    y = ans[n / 3];
  }

  return 1 + min(ans[n - 1], min(x, y));
}

int minStepto1_better(int n)
{
  int* ans = new int[n];
  for(int i = 0; i < n; i++)
  {
    ans[i] = -1;
  }

  return minStepto1_betterHelper(n, ans);
}

//DP Method
int minStepto1_DP(int n)
{
  int* ans = new int[n + 1];

  ans[1] = 0;
  ans[2] = ans[3] = 1;
  int x, y;

  for(int i = 4; i <= n; i++)
  {
    x = y = INT_MAX;

    if(i % 2 == 0)
    {
      x = ans[i / 2];
    }

    if(i % 3 == 0)
    {
      y = ans[i / 3];
    }

    ans[i] = 1 + min(ans[i - 1], min(x, y));
  }

  return ans[n];
}

int main()
{
  int n;
  cin>>n;

  int minStep1 = minStepto1(n);
  cout<<"Minimum Steps: "<<minStep1<<endl;

  int minStep2 = minStepto1_better(n);
  cout<<"Minimum Steps: "<<minStep2<<endl;

  int minStep3 = minStepto1_DP(n);
  cout<<"Minimum Steps: "<<minStep3<<endl;

  return 0;
}
