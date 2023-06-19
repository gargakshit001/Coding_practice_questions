#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int findSwapValues(int A[], int n, int B[], int m)
{
  int sum1 = 0 , sum2 = 0;

  for(int i=0;i<n;i++)
  {
    sum1 += A[i];
  }

  for(int i=0;i<m;i++)
  {
    sum2 += B[i];
  }

  sort(A, A + n);
  sort(B, B + m);

  int i = 0 , j = 0;

  while(i < n && j < m)
  {
    int val = sum1 - (A[i]) + B[j];
    int val2 = sum2 - (B[j]) + A[i];

    if(val == val2)
    {
      return 1;
    }
    if(val > val2)
    {
      i++;
    }
    else
    {
      j++;
    }
  }

  return -1;
}

int main()
{
  int arr1[] = {4, 1, 2, 1, 1, 2};
  int arr2[] = {1, 6, 3, 3};

  int m, n;
  m = sizeof(arr1) / sizeof(arr1[0]),
  n = sizeof(arr2) / sizeof(arr2[0]);
  cout<<findSwapValues(arr1, m, arr2, n);

  return 0;
}
