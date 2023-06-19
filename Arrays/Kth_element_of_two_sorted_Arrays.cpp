#include<bits/stdc++.h>
using namespace std;

int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
  int ans = 0;
  if(k > m + n)
  {
    return -1;
  }

  int i = 0, j = 0, count = 1;
  while(i < m && j < n)
  {
    if(arr1[i] < arr2[j])
    {
      if(count == k)
      {
        ans = arr1[i];
        break;
      }
      else
      {
        i++;
        count++;
      }
    }
    else
    {
      if(count == k)
      {
        ans = arr2[j];
        break;
      }
      else
      {
        j++;
        count++;
      }
    }
  }

  if(i == m)
  {
    while(j < n)
    {
      if(count == k)
      {
        ans = arr2[j];
        break;
      }
      else
      {
        j++;
        count++;
      }
    }
  }

  if(j == n)
  {
    while(i < m)
    {
      if(count == k)
      {
        ans = arr1[i];
        break;
      }
      else
      {
        i++;
        count++;
      }
    }
  }

  return ans;
}

int main()
{
  /*int Ar1[] = {2, 2, 3, 4, 9, 11, 14, 18, 20, 24, 24, 27, 30, 34, 39, 44, 44, 47, 50, 50, 52, 52, 52, 52, 56, 56, 57};
  int Ar2[] = {3, 7, 10, 13, 13, 18, 22, 25, 29, 29, 29, 29, 29, 31, 32, 36, 41, 44, 46, 51, 51, 53, 57, 60, 65, 67, 70};*/
  int Ar1[] = {2, 3, 6, 7, 9};
  int Ar2[] = {1, 4, 8, 10};
  int m = sizeof(Ar1) / sizeof(Ar1[0]);
  int n = sizeof(Ar2) / sizeof(Ar2[0]);
  cout <<kthElement(Ar1, Ar2, m, n, 5)<<endl;

  return 0;
}
/*27
2, 2, 3, 4, 9, 11, 14, 18, 20, 24, 24, 27, 30, 34, 39, 44, 44, 47, 50, 50, 52, 52, 52, 52, 56, 56, 57
3, 7, 10, 13, 13, 18, 22, 25, 29, 29, 29, 29, 29, 31, 32, 36, 41, 44, 46, 51, 51, 53, 57, 60, 65, 67, 70*/
