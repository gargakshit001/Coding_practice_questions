#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int findMinDiff(int arr[], int n, int m)
{
  if(m == 0 || n == 0)
  {
    return 0;
  }
  if(n < m)
  {
    return -1;
  }

  sort(arr, arr + n);
  int mindiff = arr[m - 1] - arr[0];
  int i = 1;
  for(int j = 0; j < n; j++)
  {
    cout<<arr[j]<<" ";
  }
  cout<<endl;
  while(i + m <= n)
  {
    int diff = arr[i + m - 1] - arr[i];
    mindiff = min(mindiff, diff);
    i++;
  }
  return mindiff;
}

int main()
{
  int arr[] = {3, 4, 1, 9, 56, 7, 9, 12};
  int n = sizeof(arr)/sizeof(arr[0]);
  int students = 5;

  cout<<findMinDiff(arr, n, students);

  //zigZag_alternate(a, n);

  return 0;
}
