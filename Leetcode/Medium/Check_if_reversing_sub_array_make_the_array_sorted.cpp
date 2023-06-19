#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool reverse_arr(int arr[], int n, int low, int high)
{
  if(low >= high)
  {
    return false;
  }

  int temp = arr[low];
  arr[low] = arr[high];
  arr[high] = temp;

  reverse_arr(arr, n, low + 1, high - 1);

  for(int i = 0; i < n - 1; i++)
  {
    if(arr[i] > arr[i + 1])
    {
      return false;
    }
  }

  return true;
}

bool checkReverse(int arr[], int n)
{
  int low = 0, high = n - 1;
  for(int i = 0; i < n - 1; i++)
  {
    if(arr[i] > arr[i + 1])
    {
      low = i;
      break;
    }
  }

  for(int i = low; i < n - 1; i++)
  {
    if(arr[i] < arr[i + 1])
    {
      high = i;

      return reverse_arr(arr, n, low, high);
    }
  }

  return true;
}

int main()
{
  int arr[] = {10,20,30,40,4,3,2,50,60,70};
  int N = sizeof(arr) / sizeof(int);
  checkReverse(arr, N)? cout << "--YES--" : cout << "--NO--";
  return 0;
}
