#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int findPlatform(int arr[], int dep[], int n)
{
  sort(arr, arr+n);
  sort(dep, dep+n);

  int i=0, j=1;
  int platform = 1;

  while(i<n && j<n)
  {
    if( arr[j] > dep[i])
    {
      i++;
    }
    else
    {
      platform++;
    }

    j++;
  }

  return platform;
}

int main()
{
  int arr[] = { 900, 940, 950, 1100, 1500, 1800 };
  int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 };
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << findPlatform(arr, dep, n);

  return 0;
}
