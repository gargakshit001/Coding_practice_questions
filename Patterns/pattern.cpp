#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n, start;
  cout<<"n: ";
  cin>>n;
  cout<<"start: ";
  cin>>start;

  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if(j <= i)
      {
        cout<<start;
      }
      else
      {
        cout<<" ";
      }
    }
    cout<<endl;
    start++;
  }
  start--;
  for(int i = n - 1; i >= 0; i--)
  {
    for(int j = 0; j < n; j++)
    {
      if(j <= i)
      {
        cout<<start;
      }
      else
      {
        cout<<" ";
      }
    }
    cout<<endl;
    start--;
  }
  return 0;
}
