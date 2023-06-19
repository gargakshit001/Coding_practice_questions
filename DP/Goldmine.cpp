#include<bits/stdc++.h>
using namespace std;

int maximumPath(int n, int** matrix)
{
  int **ans = new int*[n];
  for(int i = 0; i < n; i++)
  {
    ans[i] = new int[n];
  }

  for(int j = n - 1; j >= 0; j--)
  {
    for(int i = n - 1; i >= 0; i--)
    {
      if(j == n - 1)
      {
        ans[i][j] = matrix[i][j];
      }

      else if(i == 0)
      {
        ans[i][j] = matrix[i][j] + max(ans[i][j + 1], ans[i + 1][j + 1]);
      }

      else if(i == n - 1)
      {
        ans[i][j] = matrix[i][j] + max(ans[i][j + 1], ans[i - 1][j + 1]);
      }

      else
      {
        ans[i][j] = matrix[i][j] + max(ans[i][j + 1], max(ans[i + 1][j + 1], ans[i - 1][j + 1]));
      }
    }
  }

  int max_ele = ans[0][0];

  for(int i = 1; i < n; i++)
  {
    if(ans[i][0] > max_ele)
    {
      max_ele = ans[i][0];
    }
  }

  return max_ele;
}

int main()
{
  int n;
  cin>>n;

  int** matrix = new int* [n];
  for(int i = 0; i < n; i++)
  {
    matrix[i] = new int[n];
  }

  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      int cost;
      cin>>cost;
      matrix[i][j] = cost;
    }
  }


/*
6
0 1 4 2 8 2
4 3 6 5 0 4
1 2 4 1 4 6
2 0 7 3 2 2
3 1 5 9 2 4
2 7 0 8 5 1
*/
  cout<<maximumPath(n, matrix)<<endl;
  return 0;
}
