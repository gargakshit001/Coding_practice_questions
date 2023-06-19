#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int search(int arr[], int n)
{
  if(n == 1)
  {
    return arr[0];
  }

  for(int i = 0; i < n; i++)
  {
    if(i == n && arr[i] != arr[i - 1])
    {
      return arr[i];
    }
    if(arr[i] == arr[i + 1])
    {
      i++;
      continue;
    }
    else
    {
      return arr[i];
    }
  }

  return -1;
}

int main()
{
  int arr[] = { 1, 1, 2, 4, 4, 5, 5, 6, 6 };
  int len = sizeof(arr) / sizeof(arr[0]);

  cout<<search(arr, len);

  return 0;
}
