#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//TLE
bool binary_search(int arr[], int n, int ele)
{
  int low = 0;
  int high = n - 1;

  while(low <= high)
  {
    int mid = (high + low) / 2;

    if(arr[mid] == ele)
    {
      return true;
    }

    else if(arr[mid] > ele)
    {
      high = high - 1;
    }

    else
    {
      low = low + 1;
    }
  }
  return false;
}

vector<int> commonElements(int arr1[], int n1, int arr2[], int n2, int arr3[], int n3)
{
  vector<int> ans;

  for(int i = 0; i < n1; i++)
  {
    if(i != 0 && arr1[i] == arr1[i - 1])
    {
      continue;
    }

    if(binary_search(arr2, n2, arr1[i]) && binary_search(arr3, n3, arr1[i]))
    {
      ans.push_back(arr1[i]);
    }
  }

  if(ans.size() == 0)
  {
    ans.push_back(-1);
    return ans;
  }
  return ans;
}

//GFG
vector<int> commonElements_better(int arr1[], int n1, int arr2[], int n2, int arr3[], int n3)
{
  vector<int> ans;

  unordered_map<int, int> mp;

  for(int i = 0; i < n1; i++)
  {
    mp[arr1[i]]++;
  }

  int i = 0, j = 0;

  while(i < n2 && j < n3)
  {
    if(arr2[i] == arr3[j])
    {
      if(mp[arr2[i]] > 0)  //we are not including repetitive elements
      {
        ans.push_back(arr2[i]);
        mp[arr2[i]] = -1;
      }
      i++;
      j++;
    }
    else if(arr2[i] < arr3[j])
    {
      i++;
    }
    else
    {
      j++;
    }
  }

  return ans;
}

int main()
{
  int arr1[] = {1, 5, 10, 20, 40, 80};
  int arr2[] = {6, 10, 20, 80, 100};
  int arr3[] = {3, 10, 15, 20, 30, 70, 80, 120};
  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  int n3 = sizeof(arr3) / sizeof(arr3[0]);

  // Function call
  vector<int> ans = commonElements_better(arr1, n1, arr2, n2, arr3, n3);
  for(auto i : ans)
  {
    cout<<i<<" ";
  }
  return 0;
}
