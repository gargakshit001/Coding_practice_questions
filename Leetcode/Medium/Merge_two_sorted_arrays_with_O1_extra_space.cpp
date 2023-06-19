#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//TLE
void merge(int arr1[], int arr2[], int m, int n)
{
  int i = 0, j = 0;

  while(i < m)
  {
    if(arr1[i] < arr2[j])
    {
      i++;
    }
    else
    {
      swap(arr1[i], arr2[j]);
      sort(arr2, arr2 + n);
      i++;
    }
  }

  for(int i = 0; i < m; i++)
  {
    cout<<arr1[i]<<" ";
  }
  //cout<<endl;
  for(int i = 0; i < n; i++)
  {
    cout<<arr2[i]<<" ";
  }
}

//GFG
void merge_better(int arr1[], int arr2[], int m, int n)
{
  int i = m - 1;
  int j = 0;

  while(i >= 0 && j < n)
  {
    if(arr1[i] > arr2[j])
    {
      swap(arr1[i], arr2[j]);
      i--;
      j++;
    }
    else
    {
      break;
    }
  }

  sort(arr1, arr1 + m);
  sort(arr2, arr2 + n);

  for(int i = 0; i < m; i++)
  {
    cout<<arr1[i]<<" ";
  }
  //cout<<endl;
  for(int i = 0; i < n; i++)
  {
    cout<<arr2[i]<<" ";
  }
}

int main()
{
  int arr1[] = {2, 3, 6, 7, 9};
  int arr2[] = {1, 4, 8, 10};

  int m = sizeof(arr1) / sizeof(arr1[0]);
  int n = sizeof(arr2) / sizeof(arr2[0]);

  merge(arr1, arr2, m, n);

  return 0;
}
