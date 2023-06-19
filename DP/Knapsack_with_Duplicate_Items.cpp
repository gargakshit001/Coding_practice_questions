#include<bits/stdc++.h>
using namespace std;

int knapSack(int w, int wt[], int val[], int n)
{
  int ans[w + 1];
  memset(ans, 0, sizeof(ans));

  for(int i = 0; i <= w; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if(wt[j] <= i)
      {
        ans[i] = max(ans[i], ans[i - wt[j]] + val[j]);
      }
    }
  }
  return ans[w];
}

int main()
{
  int N = 4;
  int W = 8;
  int values[] = {10, 40, 50, 70};
  int weight[] = {1, 3, 4, 5};

  cout<<knapSack(W, weight, values, N);

  return 0;
}
