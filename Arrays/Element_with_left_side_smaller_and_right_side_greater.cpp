#include<bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n)
{
  if(n < 3)
  {
    return -1;
  }
  if(n == 3)
  {
    if(arr[1] > arr[0] && arr[1] < arr[2])
    {
      return arr[1];
    }
    else
    {
      return -1;
    }
  }

  int max_arr[n];
  int min_arr[n];
  memset(max_arr, 0, sizeof(max_arr));
  memset(min_arr, 0, sizeof(min_arr));
  max_arr[0] = arr[0];
  min_arr[n - 1] = arr[n - 1];

  for(int i = 1; i < n; i++)
  {
    if(arr[i] > max_arr[i - 1])
    {
      max_arr[i] = arr[i];
    }
    else
    {
      max_arr[i] = max_arr[i - 1];
    }
  }

  cout<<"max_arr: ";
  for(int i = 0; i < n; i++)
  {
    cout<<max_arr[i]<<" ";
  }
  cout<<endl;

  for(int i = n - 2; i >= 0; i--)
  {
    if(arr[i] < min_arr[i + 1])
    {
      min_arr[i] = arr[i];
    }
    else
    {
      min_arr[i] = min_arr[i + 1];
    }
  }

  cout<<"min_arr: ";
  for(int i = 0; i < n; i++)
  {
    cout<<min_arr[i]<<" ";
  }
  cout<<endl;

  for(int i = 1; i < n - 1 ; i++)
  {
    if(arr[i] >= max_arr[i - 1] && arr[i] <= min_arr[i + 1])
    {
      cout<<"Index: "<<i<<endl<<"Element: ";
      return arr[i];
    }
  }

  return -1;
}

int main()
{
  int arr[] = {10, 6, 3, 1, 5, 11, 6, 1, 11, 12};
  //int arr[] = {5, 1, 4, 3, 6, 8, 10, 7, 9};
  //int arr[] = {9, 8, 5, 6, 1, 10, 10};
  //int arr[] = {4, 1, 10, 2, 5, 5, 5, 12};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout<<"arr: ";
  for(int i = 0; i < n; i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  cout<<findElement(arr, n);

  return 0;
}
