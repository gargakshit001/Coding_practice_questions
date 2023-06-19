#include<iostream>
using namespace std;

int maxSumIs(int arr[], int n)
{
  int msis[n];
  int max = 0;

  for(int i = 0; i < n; i++)
  {
    msis[i] = arr[i];
  }

  for(int i = 1; i < n; i++)
  {
    for(int j = 0; j < i; j++)
    {
      if(msis[i] > msis[j] && msis[i] < msis[j] + arr[i])
      {
        msis[i] = msis[j] + arr[i];
      }
    }
  }

  for(int i = 0; i < n; i++)
  {
    if(max < msis[i])
    {
      max = msis[i];
    }
  }
  return max;
}

int main()
{
  int a[] = {1, 101, 2, 3, 100, 4, 5};
  int n = sizeof(a) / sizeof(a[0]);
  cout<<maxSumIs(a, n)<<endl;


  return 0;
}
