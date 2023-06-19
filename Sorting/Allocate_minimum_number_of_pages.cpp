#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int n, int m, int mid)
{
  int studentCount = 1;
  int pageSum = 0;

  for(int i = 0; i < n; i++)
  {
    if(arr[i] > mid)
    {
      return false;
    }

    if(pageSum + arr[i] > mid)
    {
      studentCount++;
      pageSum = arr[i];

      if(studentCount > m)
      {
        return false;
      }
    }
    else
    {
      pageSum += arr[i];
    }
  }
  return true;
}

int findPages(int arr[], int n, int m)
{
  if(n < m)
  {
    return -1;
  }

  int start = 0, ans = INT_MAX, sum = 0;
  for(int i = 0; i < n; i++)
  {
    sum += arr[i];
  }

  int end = sum;
  while(start <= end)
  {
    int mid = (end + start) / 2;
    if(isPossible(arr, n, m, mid))
    {
      ans = mid;
      end = mid - 1;
    }
    else
    {
      start = mid + 1;
    }
  }

  return ans;
}

int main()
{
  int arr[] = {15, 10, 19, 10, 5, 18, 7}; //5 7 10 10 15 18 19
  int n = sizeof(arr) / sizeof(arr[0]);
  int m = 5; // No. of students
  cout << "Minimum number of pages = "<< findPages(arr, n, m) << endl;

  return 0;
}
