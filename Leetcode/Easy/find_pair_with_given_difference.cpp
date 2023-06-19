#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//Time Complexity: O(n*logn) :: Space Complexity: O(1);
bool findPair(int arr[], int size, int n)
{
  sort(arr, arr + size);
  int i = 0;
  int j = 1;

  while(i < size && j < size)
  {
    if(i != j && (arr[i] - arr[j] == n || arr[j] - arr[i] == n))
    {
      cout<<i<<" "<<j;
      return true;
    }
    else if(arr[i] - arr[j] < n)
    {
      i++;
    }
    else
    {
      j++;
    }
  }
  cout<<"No such pair";
  return false;
}

int main()
{
  int arr[] = {1, 8, 30, 40, 100};
  int n = sizeof(arr)/sizeof(arr[0]);
  int diff = -22;

  findPair(arr, n, diff);
  cout<<endl;
  //zigZag_alternate(a, n);

  return 0;
}
