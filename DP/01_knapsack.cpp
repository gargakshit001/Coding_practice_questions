#include<bits/stdc++.h>
using namespace std;

int knapSack(int w, int wt[], int val[], int n)
{
  int **ans = new int*[n + 1];
  for(int i = 0; i <= n; i++)
  {
    ans[i] = new int[w + 1];
  }

  for(int i = 0; i <= n; i++)
  {
    for (int j = 0; j < w + 1; j++)
    {
      ans[i][j] = 0;
    }
  }

  for(int i = 1; i <= n; i++)
  {
    for(int j = 1; j <= w; j++)
    {
      if(j >= wt[i - 1])
      {
        int remWt = j - wt[i - 1];
        if(ans[i - 1][remWt] + val[i - 1] > ans[i - 1][j])
        {
          ans[i][j] = ans[i - 1][remWt] + val[i - 1];
        }
        else
        {
          ans[i][j] = ans[i - 1][j];
        }
      }
      else
      {
        ans[i][j] = ans[i - 1][j];
      }
    }
  }

  return ans[n][w];
}

int main()
{
  int N = 3;
  int W = 4;
  int values[] = {1,2,3};
  int weight[] = {4,5,1};

  cout<<knapSack(W, weight, values, N);

  return 0;
}
