/*
A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time.
Implement a method to count how many possible ways the child can run up to the stairs.
You need to return all possible number of ways. Time complexity of your code should be O(n).
*/

#include<iostream>
using namespace std;

//Brute Force Method
long staircase(int n)
{
  if(n == 0 || n == 1)
  {
    return 1;
  }

  if(n == 2)
  {
    return 2;
  }

  if(n == 3)
  {
    return 4;
  }

  long x = staircase(n - 1);
  long y = staircase(n - 2);
  long z = staircase(n - 3);

  return x + y + z;
}

//Memorization Method
long staircase_betterHelper(int n, int* ans)
{
  if(n == 0 || n == 1)
  {
    ans[n] = 1;
    return 1;
  }

  if(n == 2)
  {
    ans[n] = 2;
    return 2;
  }

  if(n == 3)
  {
    ans[n] = 4;
    return 4;
  }

  if(ans[n - 1] == 0)
  {
    ans[n - 1] = staircase_betterHelper(n - 1, ans);
  }

  if(ans[n - 2] == 0)
  {
    ans[n - 2] = staircase_betterHelper(n - 2, ans);
  }

  if(ans[n - 3] == 0)
  {
    ans[n - 3] = staircase_betterHelper(n - 3, ans);
  }

  ans[n] = ans[n - 1] + ans[n - 2] + ans[n - 3];
  return ans[n];
}

long staircase_better(int n)
{
  int* ans = new int[n];
  for(int i = 0; i < n; i++)
  {
    ans[i] = 0;
  }

  return staircase_betterHelper(n, ans);
}

//DP Method
long staircase_DP(int n)
{
  int* ans = new int[n + 1];

  ans[0] = ans[1] = 1;
  ans[2] = 2;
  ans[3] = 4;

  for(int i = 4 ; i <= n; i++)
  {
    ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 3];
  }

  return ans[n];
}

int main()
{
  int n;
  cin>>n;

  cout<<"Number of ways: "<<staircase(n)<<endl;
  cout<<"Number of ways: "<<staircase_better(n)<<endl;
  cout<<"Number of ways: "<<staircase_DP(n)<<endl;

  return 0;
}
