#include<bits/stdc++.h>
using namespace std;

//TLE
/*int findElement(int arr[], int n)
{
  int low = 0;
  int high = n - 1;
  int mid = high / 2;
  int leftSum = 0;
  int rightSum = 0;

  if(n < 3)
  {
    return -1;
  }

  if(n == 3)
  {
    if(arr[0] == arr[2])
    {
      return arr[1];
    }
    else
    {
      return -1;
    }
  }

  for(int i = 0; i < mid; i++)
  {
    leftSum += arr[i];
  }
  for(int j = mid + 1; j < n; j++)
  {
    rightSum += arr[j];
  }

  while(mid < high || mid > low)
  {
    if(leftSum == rightSum)
    {
      return arr[mid];
    }
    else if(leftSum < rightSum)
    {
      leftSum += arr[mid];
      rightSum = rightSum - arr[mid + 1];
      mid = mid + 1;
    }
    else
    {
      leftSum = leftSum - arr[mid - 1];
      rightSum += arr[mid];
      mid = mid - 1;
    }
  }

  return -1;
}*/

//Better Approach
int findElement(int arr[], int n)
{
  if(n == 1)
  {
    return 1;
  }

  if(n ==2)
  {
    return -1;
  }

  int mid = 1,  leftSum = 0, rightSum = 0;

  for(int i = 0; i < mid; i++)
  {
    leftSum += arr[i];
  }

  for(int i = n - 1; i > mid; i--)
  {
    rightSum += arr[i];
  }

  while(mid < n)
  {
    if(leftSum == rightSum)
    {
      return arr[mid];
    }
    else
    {
      leftSum += arr[mid];
      rightSum = rightSum - arr[mid + 1];
      mid = mid + 1;
    }
  }

  return -1;

}

int main()
{
  int arr[] = {2, 3, 4, 1, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout<<findElement(arr, n);
}
