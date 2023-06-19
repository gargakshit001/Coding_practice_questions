#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int subArraySum(vector<int>& arr, int sum)
{
  int n = arr.size();

  for(int i = 0; i < n; i++)
  {
    int s = 0;
    for(int j = i; j < n; j++)
    {
      s += arr[j];
      if(s == sum)
      {
        cout<<"Sum found between indexes "<<i<<" and "<<j;
        return 0;
      }
    }
  }
  cout<<"No subarray found";
  return 0;
}

int subArraySum_better(vector<int>& arr, int sum)
{
  int s = arr[0];
  int start = 0;
  int n = arr.size();

  for(int i = 1; i < n; i++)
  {
    while(s > sum && start < i - 1)
    {
      s = s - arr[start];
      start++;
    }

    if(s == sum)
    {
      cout<<"Sum found between indexes "<<start<<" and "<<i - 1;
      return 1;
    }
    if(i < n)
    {
      s = s + arr[i];
    }
  }

  cout<<"No subarray found";
  return 0;
}

int main()
{
  vector<int> arr = {1, 4, 0, 0, 3, 10, 5};
  vector<int> arr1 = {15, 5, 4, 8, 9, 2, 10, 23};
  int k = 15;
  int k1 = 26;
  int ans = subArraySum(arr, k);
  cout<<endl;
  int ans1 = subArraySum_better(arr1, k1);
  //cout<<ans<<endl;

  return 0;
}
