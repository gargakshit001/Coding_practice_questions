#include<bits/stdc++.h>
#include<iostream>
#define bool int
#define R 6
#define C 5
using namespace std;

void printMaxSubSquare(bool M[R][C])
{
  if(R == 1 || C == 1)
  {
    cout<<1;
  }
  int **sum = new int* [R];
  for(int i = 0; i < R; i++)
  {
    sum[i] = new int [C];
  }

  //For 1st Row
  for(int i = 0; i < C; i++)
  {
    sum[0][i] = M[0][i];
  }

  //For 1st Column
  for(int j = 0; j < R; j++)
  {
    sum[j][0] = M[j][0];
  }

  for(int i = 1; i < R; i++)
  {
    for(int j = 1; j < C; j++)
    {
      if(M[i][j] == 1)
      {
        sum[i][j] = min(sum[i - 1][j - 1], min(sum[i - 1][j], sum[i][j - 1])) + 1;
      }
      else
      {
        sum[i][j] = 0;
      }
    }
  }

  int max_ele = INT_MIN;
  for(int i = 1; i < R; i++)
  {
    for(int j = 1; j < C; j++)
    {
      max_ele = max(max_ele, sum[i][j]);
    }
  }

  for(int i = 0; i < max_ele; i++)
  {
    for(int j = 0; j < max_ele; j++)
    {
      cout<<1<<" ";
    }
    cout<<endl;
  }
}

int main()
{
    bool M[R][C] = {{0, 1, 1, 0, 1},
                    {1, 1, 0, 1, 0},
                    {0, 1, 1, 1, 0},
                    {1, 1, 1, 1, 0},
                    {1, 1, 1, 1, 1},
                    {0, 0, 0, 0, 0}};

    printMaxSubSquare(M);
}
