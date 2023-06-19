#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void kSmallestPair(int arr1[], int n1, int arr2[], int n2, int k)
{
  if(k > n1 * n2)
  {
    cout<<"No Pair";
    return;
  }

  if(n1 == 0 || n2 == 0)
  {
    cout<<"No Pair";
    return;
  }

  int index2[n1];
  memset(index2, 0, sizeof(index2));

  while(k > 0)
  {
    int min_index = 0;
    int min_sum = INT_MAX;

    for(int i = 0; i < n1; i++)
    {
      if(index2[i] < n2 && min_sum > arr1[i] + arr2[index2[i]])
      {
        min_index = i;
        min_sum = arr1[i] + arr2[index2[i]];
      }
    }
    cout<<"("<<arr1[min_index]<<", "<<arr2[index2[min_index]]<<") ";
    index2[min_index]++;
    k--;
  }
}

int main()
{
  int arr1[] = {1, 3, 11};
  int n1 = sizeof(arr1) / sizeof(arr1[0]);

  int arr2[] = {2, 4, 8};
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  int k = 4;
  kSmallestPair( arr1, n1, arr2, n2, k);

  return 0;
}
