#include<iostream>
#include<cmath>
using namespace std;

//Brtue Force Method
countBT(int h)
{
  if(h == 0 || h == 1)
  {
    return 1;
  }

  int x = countBT( h - 1);
  int y = countBT(h - 2);

  int mod = pow(10, 9) + 7;

  int temp1 = (int)(((long)(x) * x) % mod);
  int temp2 = (int)((2 * (long)(x) * y) % mod);
  int ans = temp1 + temp2;

  return ans;
}

//Memorization Method
int countBT_betterHelper(int h, int* ans)
{
  if(h == 0 || h == 1)
  {
    ans[h] = 1;
    return 1;
  }

  if(ans[h - 1] == 0)
  {
    ans[h - 1] = countBT_betterHelper(h - 1, ans);
  }

  if(ans[h - 2] == 0)
  {
    ans[h - 2] = countBT_betterHelper(h - 2, ans);
  }

  ans[h] = (ans[h - 1]) * (ans[h - 1] + 2 * ans[h - 2]);
  return ans[h];
}

int countBT_better(int h)
{
  int* ans = new int[h];
  for(int i = 0; i < h; i++)
  {
    ans[i] = 0;
  }

  return countBT_betterHelper(h, ans);
}

//DP Method
countBT_DP(int h)
{
  int* ans = new int[h + 1];

  ans[0] = ans[1] = 1;

  for(int i = 2; i <= h; i++)
  {
    ans[i] = ans[i - 1] * (ans[i - 1] + 2 * ans[i - 2]);
  }

  return ans[h];
}

int main()
{
  int h;
  cin>>h;

  cout<<"Number of trees: "<<countBT(h)<<endl;
  cout<<"Number of trees: "<<countBT_better(h)<<endl;
  cout<<"Number of trees: "<<countBT_DP(h)<<endl;
}
