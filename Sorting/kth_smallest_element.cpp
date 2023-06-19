#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int kthLargest(int arr[], int l, int r, int k)
{
  int key = (r - l + 1) - k + 1;

  priority_queue<int> pq;

  for(int i = r; i >= 0; i--)
  {
    pq.push(arr[i]);

    if(pq.size() > key)
    {
      pq.pop();
    }
  }

  cout<<"Kth Largest Element is: ";
  return pq.top();
}

int kthSmallest(int arr[], int l, int r, int k)
{
  if(k > r - l + 1)
  {
    return -1;
  }

  priority_queue<int> pq;

  for(int i = r; i >= 0; i--)
  {
    pq.push(arr[i]);
    //cout<<pq.top()<<endl;
    if(pq.size() > k)
    {
      pq.pop();
    }
  }

  cout<<"Kth Smallest Element is: ";
  return pq.top();
}

int main()
{
  int arr[] = {3, 5, 10, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  for(int i = 0; i < n; i++)
  {
    cout<<arr[i]<<" ";
  }

  int k;
  cout<<endl<<"Enter k: ";
  cin>>k;
  cout<<kthSmallest(arr, 0, n - 1, k)<<endl;
  cout<<kthLargest(arr, 0, n - 1, k);
}
