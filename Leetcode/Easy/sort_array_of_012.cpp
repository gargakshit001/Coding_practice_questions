#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void sort012(int a[], int arr_size)
{
  int count0 = 0;
  int count1 = 0;
  int count2 = 0;

  for(int i = 0; i < arr_size; i++)
  {
    if(a[i] == 0)
    {
      count0++;
    }
    else if(a[i] == 1)
    {
      count1++;
    }
    else
    {
      count2++;
    }
  }
  int i = 0;
  while(count0 > 0)
  {
    a[i++] = 0;
    count0--;
  }
  while(count1 > 0)
  {
    a[i++] = 1;
    count1--;
  }
  while(count2 > 0)
  {
    a[i++] = 2;
    count2--;
  }
}

void printArray(int arr[], int arr_size)
{
  for(int i = 0; i < arr_size; i++)
  {
    cout<<arr[i]<<" ";
  }
}

int main()
{
  int arr[] = {0, 1, 2, 0, 1, 2, 0};
  int n = sizeof(arr)/sizeof(arr[0]);
  sort012(arr, n);
  printArray(arr, n);
  
  return 0;
}
