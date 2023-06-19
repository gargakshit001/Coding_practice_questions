#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void zigZag(vector<int>& arr, int N)
{
  for(int i = 0; i < arr.size() - 1; i++)
  {
    if(i % 2 == 0)
    {
      if(arr.at(i) > arr.at(i + 1))
      {
        swap(arr[i], arr[i + 1]);
      }
      else
      {
        continue;
      }
    }
    else
    {
      if(arr[i] < arr[i + 1])
      {
        swap(arr[i], arr[i + 1]);
      }
      else
      {
        continue;
      }
    }
  }

  for(int i = 0; i < arr.size(); i++)
  {
    cout<<arr.at(i)<<" ";
  }
}

void zigZag_alternate(vector<int>& arr, int n)
{
  // Flag true indicates relation "<" is expected,
  // else ">" is expected. The first expected relation
  // is "<"
  bool flag = true;

  for(int i = 0; i < n; i++)
  {
    if(flag)
    {
      if(arr[i] > arr[i + 1])
      {
        swap(arr[i], arr[i + 1]);
      }
      else
      {
        continue;
      }
    }
    else
    {
      if(arr[i] < arr[i + 1])
      {
        swap(arr[i], arr[i + 1]);
      }
      else
      {
        continue;
      }
    }

    flag = !flag;
  }

  for(int i = 0; i < arr.size(); i++)
  {
    cout<<arr.at(i)<<" ";
  }
}

int main()
{
  vector<int> a = {4, 3, 7, 8, 6, 2, 1};
  int n = a.size();

  zigZag(a, n);
  cout<<endl;
  zigZag_alternate(a, n);

  return 0;
}
