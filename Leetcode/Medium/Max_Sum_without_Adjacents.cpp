#include<iostream>
#include<vector>
using namespace std;

int findMaxSum(vector<int> &arr, int n)
{
  int incl = arr[0];
  int excl = 0;
  int excl_new;

  for(int i = 1; i < n; i++)
  {
    excl_new = max(incl, excl);
    incl = excl + arr[i];
    excl = excl_new;
  }

  return max(incl, excl);
}

int main()
{
  vector<int> arr = {5, 5, 10, 100, 10, 50};

  int n = arr.size();

  cout<<findMaxSum(arr, n);

  return 0;
}
