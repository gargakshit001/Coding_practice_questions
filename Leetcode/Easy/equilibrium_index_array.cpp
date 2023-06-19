#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int equalSum(int arr[], int n)
{
  if(n <= 2)
  {
    return -1;
  }
  if(n == 3)
  {
    if(arr[0] == arr[n - 1])
    {
      return 1;
    }
    else
    {
      return -1;
    }
  }

  for(int i = 1; i < n - 1; i++)
  {
    int sum_low = 0;
    int sum_high = 0;
    for(int j = 0; j < i; j++)
    {
      sum_low += arr[j];
    }
    for(int k = i + 1; k < n; k++)
    {
      sum_high += arr[k];
    }
    if(sum_low == sum_high)
    {
      return i;
    }
  }
  return -1;
}

int equalSum_better(int arr[], int n)
{
  int leftSum = 0;
  int sum = 0;

  for(int i = 0; i < n; i++)
  {
    sum += arr[i];
  }

  for(int i = 0; i < n; i++)
  {
    sum -= arr[i];
    if(sum == leftSum)
    {
      return i;
    }
    else
    {
      leftSum += arr[i];
    }
  }
  return -1;
}

int main()
{
  int a[]= {-7, 1, 5, 2, -4, 3, 0};
  int n = sizeof(a) / sizeof(a[0]);

  cout<<equalSum(a, n)<<endl;
  cout<<equalSum_better(a, n)<<endl;
  
  return 0;
}
