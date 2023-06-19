#include <bits/stdc++.h>
#include<iostream>
using namespace std;

//Time Complexity: O(n^2); Space Complexity: O(1)
int countTriplet_better(int arr[], int n, int sum)
{
  int count = 0;
  sort(arr, arr + n);

  for(int i = 0; i < n - 2; i++)
  {
    int s = arr[i];
    int l = i + 1;
    int r = n - 1;

    while(l < r)
    {
      if(s + arr[l] + arr[r] >= sum)
      {
        r--;
      }
      else
      {
        count += r-l;
        l++;
      }
    }
  }
  return count;
}

//Time Complexity: O(n^3); Space Complexity: O(1)
int countTriplet(int arr[], int n, int sum)
{
  int count = 0;

  for(int i = 0; i < n - 2; i++)
  {
    for(int j = i + 1; j < n - 1; j++)
    {
      for(int k = j + 1; k < n; k++)
      {
        if(arr[i] + arr[j] + arr[k] < sum)
        {
          count++;
        }
      }
    }
  }
  return count;
}

int main()
{
  int arr[] = {5, 1, 3, 4, 7};
  int n = sizeof(arr) / sizeof(arr[0]);
  int sum = 12;
  // Function call
  cout<<countTriplet_better(arr, n, sum);
  cout<<endl;
  cout<<countTriplet(arr, n, sum);
  return 0;
}
