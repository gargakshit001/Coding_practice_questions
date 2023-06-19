#include<iostream>
using namespace std;

//Brute Force Method
int minCostPath_Helper(int** matrix, int m, int n, int i, int j)
{
  //Base Case
  if(i == m - 1 && j == n - 1)
  {
    return matrix[i][j];
  }

  if(i >= m || j >= n)
  {
    return INT_MAX;
  }

  //Recursive Calls
  int x, y, z;

  x = minCostPath_Helper(matrix, m, n, i, j + 1);
  y = minCostPath_Helper(matrix, m, n, i + 1, j + 1);
  z = minCostPath_Helper(matrix, m, n, i + 1, j);

  int minCost = min(x, min(y, z));

  return minCost + matrix[i][j];
}

int minCostPath(int** matrix, int m, int n)
{
  return minCostPath_Helper(matrix, m, n, 0, 0);
}

//Memorization Method
int minCostPath_betterHelper(int** matrix, int m, int n, int i, int j, int** ans)
{
  if(i == m - 1 && j == n - 1)
  {
    return matrix[i][j];
  }

  if(i >= m || j >= n)
  {
    return INT_MAX;
  }

  int x = minCostPath_betterHelper(matrix, m, n, i + 1, j, ans);
  if(x < INT_MAX)
  {
    ans[i + 1][j] = x;
  }
  int y = minCostPath_betterHelper(matrix, m, n, i + 1, j + 1, ans);
  if(y < INT_MAX)
  {
    ans[i + 1][j + 1] = y;
  }
  int z = minCostPath_betterHelper(matrix, m, n, i, j + 1, ans);
  if(z < INT_MAX)
  {
    ans[i][j + 1] = z;
  }

  ans[i][j] = min(x, min(y, z)) + matrix[i][j];
  return ans[i][j];
}

int minCostPath_better(int** matrix, int m, int n)
{
  int** ans = new int* [m];
  for(int i = 0; i < m; i++)
  {
    ans[i] = new int[n];
  }

  for(int i = 0; i < m; i++)
  {
    for(int j = 0; j < n; j++)
    {
      ans[i][j] = -1;
    }
  }

  return minCostPath_betterHelper(matrix, m, n, 0, 0, ans);
}

//DP Method
int minCostPath_DP(int** matrix, int m, int n)
{
  int** ans = new int* [m];
  for(int i = 0; i < m; i++)
  {
    ans[i] = new int[n];
  }

  ans[m - 1][n - 1] = matrix[m - 1][n - 1];

  //Last Row
  for(int j = n - 2; j >= 0; j--)
  {
    ans[m - 1][j] = matrix[m - 1][j] + ans[m - 1][j + 1];
  }

  //Last Column
  for(int i = m - 2; i >= 0; i--)
  {
    ans[i][n - 1] = matrix[i][n -  1] + ans[i + 1][n - 1];
  }

  for(int i = m - 2; i >= 0; i--)
  {
    for(int j = n - 2; j >= 0; j--)
    {
      ans[i][j] = min(ans[i + 1][j], min(ans[i + 1][j + 1], ans[i][j + 1])) + matrix[i][j];
    }
  }
  return ans[0][0];
}

int main()
{
  int m, n;
  cin>>m>>n;

  int** matrix = new int* [m];
  for(int i = 0; i < m; i++)
  {
    matrix[i] = new int[n];
  }

  for(int i = 0; i < m; i++)
  {
    for(int j = 0; j < n; j++)
    {
      int cost;
      cin>>cost;
      matrix[i][j] = cost;
    }
  }

  cout<<"Min Cost Path: "<<minCostPath(matrix, m, n)<<endl;
  cout<<"Min Cost Path: "<<minCostPath_better(matrix, m, n)<<endl;
  cout<<"Min Cost Path: "<<minCostPath_DP(matrix, m, n);

  return 0;
}
