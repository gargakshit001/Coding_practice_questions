#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int key)
{
  int low = 0;
  int high = n - 1;

  while(low <= high)
  {
    int mid = (high + low) / 2;

    if(arr[mid] == key)
    {
      return 1;
    }
    else if(arr[mid] < key)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }

  return -1;
}

int main()
{
  int arr[] = {10, 20, 30, 50, 60, 80, 110, 130, 140, 170};
  int n = sizeof(arr) / sizeof(arr[0]);
  int key = 10;

  int result = binarySearch(arr, n, key);
  (result == -1)
  ? cout << "Element is not present in array"
  : cout << "Element is present";

  return 0;
}
