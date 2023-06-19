#include<iostream>
#include<unordered_map>
using namespace std;

void findFourElements(int arr[], int n, int X)
{
  if(n < 4)
  {
    cout<<"No elements";
    return;
  }

  if(n == 4)
  {
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
      sum += arr[i];
    }
    if(sum == X)
    {
      cout<<"Elements are: ";
      for(int i = 0; i < n; i++)
      {
        cout<<arr[i]<<", ";
      }
      return;
    }
    else
    {
      cout<<"No elements";
      return;
    }
  }

  unordered_map<int, pair<int, int>> mp;

  for(int i = 0; i < n - 1; i++)
  {
    for(int j = i + 1; j < n; j++)
    {
      mp[arr[i] + arr[j]] = {i, j};
    }
  }

  for(int i = 0; i < n - 1; i++)
  {
    for(int j = i + 1; j < n; j++)
    {
      int sum = arr[i] + arr[j];

      if(mp.find(X - sum) != mp.end())
      {
        pair<int, int> p = mp[X - sum];

        if(p.first != i && p.second != i && p.first != j && p.second != j)
        {
          cout<<"The elements are: "<<arr[i]<<", "<<arr[j]<<", "<<arr[p.first]<<", "<<arr[p.second];
          return;
        }
      }
    }
  }
  cout<<"No elements";
  return;
}

int main()
{
    int arr[] = {10, 2, 3, 4, 5, 7, 8, 9};
    int arr1[] = { 10, 20, 30, 40, 1, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int X = 30;

    // Function call
    findFourElements(arr, n, X);
    return 0;
}
