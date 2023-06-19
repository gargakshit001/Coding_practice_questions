#include<bits/stdc++.h>
using namespace std;

int findMidSum(int arr1[], int arr2[], int n)
{
  int x = 0;

  for(int i = n - 1; i >= 0; i--)
  {
    if(arr1[i] > arr2[x])
    {
      swap(arr1[i], arr2[x]);
      x++;
    }
    else
    {
      break;
    }
  }
  sort(arr1, arr1 + n);
  sort(arr2, arr2 + n);

  return arr1[n - 1] + arr2[0];
}

int main()
{
  int Ar1[] = {2, 2, 3, 4, 9, 11, 14, 18, 20, 24, 24, 27, 30, 34, 39, 44, 44, 47, 50, 50, 52, 52, 52, 52, 56, 56, 57};
  int Ar2[] = {3, 7, 10, 13, 13, 18, 22, 25, 29, 29, 29, 29, 29, 31, 32, 36, 41, 44, 46, 51, 51, 53, 57, 60, 65, 67, 70};
  /*int Ar1[] = {1, 12, 15, 26, 38};
  int Ar2[] = {2, 13, 17, 30, 45};*/
  int n = sizeof(Ar1) / sizeof(Ar1[0]);
  cout <<findMidSum(Ar1, Ar2, n)<<endl;

  return 0;
}
