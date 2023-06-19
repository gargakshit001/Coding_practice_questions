#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool pairInSortedRotated(int arr[], int n, int x)
{
  int i;
  for(i = 0; i < n - 1; i++)
  {
    if(arr[i] > arr[i + 1])
    {
      break;
    }
  }

  int s = (i + 1) % n;
  int l = i;

  while(s != l)
  {
    if(arr[s] + arr[l] == x)
    {
      return true;
    }

    if(arr[s] + arr[l] < x)
    {
      s = (s + 1) % n;
    }

    else
    {
      l = (n + l - 1) % n;
    }
  }
  return false;
}

int main()
{
    int arr[] = { 11, 15, 6, 8, 9, 10 };
    int X = 25;
    int N = sizeof(arr) / sizeof(arr[0]);

    // Function call
    if (pairInSortedRotated(arr, N, X))
    {
      cout << "true";
    }
    else
    {
      cout << "false";
    }

    return 0;
}
