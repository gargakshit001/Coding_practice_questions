#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int firstElement(int arr[], int n, int k)
{
  map<int, int> mp;

  for(int i = 0; i < n; i++)
  {
    mp[arr[i]]++;
  }

  for(int i = 0; i < n; i++)
  {
    if(mp[arr[i]] == k)
    {
      return arr[i];
    }
  }

  return -1;
}

int main()
{
  int arr[] = {7, 6, 7, 10, 3, 2, 8, 9, 4, 7, 2, 5, 2, 8, 4};
  int n = sizeof(arr) / sizeof(arr[0]);
  int k = 1;
  cout << firstElement(arr, n, k);

  return 0;
}
