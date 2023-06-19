#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int minCostToMakeElementEqual(int arr[], int n)
{
  // If there are odd elements, we choose
  // middle element
  int y, sum = 0;
  if (n % 2 == 1)
  {
    y = arr[n / 2];
  }

  // If there are even elements, then we choose
  // the average of middle two.
  else
  {
    y = (arr[n / 2] + arr[(n - 2) / 2]) / 2;
  }

  for(int i = 0; i < n; i++)
  {
    sum += abs(arr[i] - y);
  }
  return sum;
}

int main()
{
  int arr[] = {10, 15, 16, 20, 100, 1000, 1001, 1002};
  int N = sizeof(arr) / sizeof(int);
  cout << minCostToMakeElementEqual(arr, N);
  return 0;
}
