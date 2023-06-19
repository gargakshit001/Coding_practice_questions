#include<bits/stdc++.h>
using namespace std;

//Brute Force
void printLeaders(int arr[], int n)
{
  for(int i = 0; i < n; i++)
  {
    int j;
    for(j = i + 1; j < n; j++)
    {
      if(arr[i] < arr[j])
      {
        break;
      }
    }
    if(j == n)
    {
      cout<<arr[i]<<" ";
    }
  }
}

//Better Approach
void PrintLeaders(int arr[], int n)
{
  int maxRight = arr[n - 1];
  cout<<maxRight<<" ";

  for(int i = n - 2; i >= 0; i--)
  {
    if(arr[i] >= maxRight)
    {
      cout<<arr[i]<<" ";
      maxRight = arr[i];
    }
  }
}

int main()
{
  int arr[] = {16, 17, 4, 3, 5, 2};
  int n = sizeof(arr) / sizeof(arr[0]);

  printLeaders(arr, n);
  cout<<endl;
  PrintLeaders(arr, n);
}
