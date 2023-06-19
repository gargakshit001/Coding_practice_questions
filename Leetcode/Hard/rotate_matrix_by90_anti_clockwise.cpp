#include<bits/stdc++.h>
#include<iostream>
#define N 4
using namespace std;

void rotateMatrix(int mat[][N])
{
  for(int i = 0; i < N / 2; i++)
  {
    for(int j = i; j < N - 1 - i; j++)
    {
      int temp = mat[i][j];
      mat[i][j] = mat[j][N - i - 1];
      mat[j][N - i - 1] = mat[N - i - 1][N - 1 - j];
      mat[N - i - 1][N - j - 1] = mat[N - 1 - j][i];
      mat[N - j - 1][i] = temp;
    }
  }

  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N; j++)
    {
      cout<<mat[i][j]<<" ";
    }
    cout<<endl;
  }
}

int main()
{
  int mat[N][N] = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 }
                  };
  rotateMatrix(mat);

  return 0;

}
