#include<bits/stdc++.h>
using namespace std;

//Brute Force
bool areEqual(int arr1[], int arr2[], int n, int m)
{
  if(n != m)
  {
    return -1;
  }

  sort(arr1, arr1 + n);
  sort(arr2, arr2 + m);

  for(int i = 0; i < n; i++)
  {
    if(arr1[i] != arr2[i])
    {
      return -1;
    }
  }

  return 1;
}

bool AreEqual(int arr1[], int arr2[], int n, int m)
{
  if(n != m)
  {
    return -1;
  }

  unordered_map<int, int> map;

  for(int i = 0; i < n; i++)
  {
    map[arr1[i]]++;
  }

  for(int i = 0; i < n; i++)
  {
    if(map.find(arr2[i]) == map.end())
    {
      return -1;
    }

    if(map[arr2[i]] == 0)
    {
      return false;
    }

    map[arr2[i]]--;
  }

  return 1;
}

int main()
{
  int arr1[] = { 3, 5, 2, 5, 2 };
  int arr2[] = { 2, 3, 5, 5, 2 };
  int n = sizeof(arr1) / sizeof(int);
  int m = sizeof(arr2) / sizeof(int);

  if (AreEqual(arr1, arr2, n, m))
  {
    cout << "Yes";
  }
  else
  {
    cout << "No";
  }

  return 0;
}
