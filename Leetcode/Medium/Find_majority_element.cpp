#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int findCandidate(int arr[], int n)
{
  int maj_index = 0, count = 1;
  for(int i = 0; i < n; i++)
  {
    if(arr[maj_index] == arr[i])
    {
      count++;
    }
    else
    {
      count--;
      if(count == 0)
      {
        maj_index = i;
        count = 1;
      }
    }
  }
  return arr[maj_index];
}

bool isMajority(int arr[], int n, int cand)
{
  int count = 0;
  for(int i = 0; i < n; i++)
  {
    if(arr[i] == cand)
    {
      count++;
    }
  }

  if(count > n / 2)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void printMajority(int arr[], int n)
{
  int cand = findCandidate(arr, n);

  if(isMajority(arr, n, cand))
  {
    cout<<"Majority Element: "<<cand;
  }
  else
  {
    cout<<"No Majority Element";
  }
}

//Time Complexity: O(n); Space Complexity: O(n)
int majority(int arr[], int n)
{
  unordered_map<int, int> mp;

  for(int i = 0; i < n; i++)
  {
    mp[arr[i]]++;
  }

  int element;
  int count = INT_MIN;
  for(auto i = mp.begin(); i != mp.end(); i++)
  {
    if(i->second > count)
    {
      count = i->second;
      element = i->first;
    }
  }

  if(count > n / 2)
  {
    cout<<"majority element: ";
    return element;
  }

  else
  {
    cout<<"No majority element";
    return -1;
  }
}

int main()
{
  int arr[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout<<majority(arr, n)<<endl;
  printMajority(arr, n);
  return 0;
}
