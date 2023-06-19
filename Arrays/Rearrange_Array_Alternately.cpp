#include<bits/stdc++.h>
using namespace std;

//Time Complexity: O(n)
//Auxiliary Space: O(n)
void rearrange(int arr[], int n)
{
  int ans[n];
  int x = 0;
  for(int i = 0; i < n; i+=2)
  {
      ans[i] = arr[n - 1 - x];
      x++;
  }

  int y = 0;
  for(int i = 1; i < n; i+=2)
  {
    ans[i] = arr[y];
    y++;
  }

  for(int i = 0; i < n; i++)
  {
    arr[i] = ans[i];
  }
}

//Time Complexity: O(n)
//Auxiliary Space: O(1)
void Rearrange(int arr[], int n)
{
  int min_index = 0;
  int max_index = n - 1;
  int max_ele = arr[n - 1] + 1;

  for(int i = 0; i < n; i++)
  {
    if(i % 2 == 0)
    {
      arr[i] = arr[i] + ((arr[max_index] % max_ele) * max_ele);
      max_index--;
    }
    else
    {
      arr[i] = arr[i] + ((arr[min_index] % max_ele) * max_ele);
      min_index++;
    }
  }

  for(int i = 0; i < n; i++)
  {
    arr[i] = arr[i] / max_ele;
  }
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int n = sizeof(arr) / sizeof(arr[0]);

  for(int i = 0; i < n; i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;

  /*rearrange(arr, n);
  for(int i = 0; i < n; i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;*/

  Rearrange(arr, n);
  for(int i = 0; i < n; i++)
  {
    cout<<arr[i]<<" ";
  }

  return 0;
}
