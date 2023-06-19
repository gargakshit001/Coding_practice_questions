//Kadane's Algorithm

#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n)
{
  int current_best = arr[0];
  int overall_best = arr[0];

  for(int i = 1; i < n; i++)
  {
    if(current_best + arr[i] > arr[i])
    {
      current_best += arr[i];
    }
    else
    {
      current_best = arr[i];
    }

    if(current_best > overall_best)
    {
      overall_best = current_best;
    }
  }

  return overall_best;
}

int main()
{
  int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout<<maxSubarraySum(arr, n);

  return 0;
}
