#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector<pair<int,int>> allPairs(int arr1[], int arr2[], int n, int m, int sum)
{
  vector<pair<int, int>> ans;

  sort(arr1, arr1 + n);
  sort(arr2, arr2 + m);
  reverse(arr2, arr2 + m);

  int start1 = 0, start2 = 0;
  while(start1 != n && start2 != m)
  {
    if(arr1[start1] + arr2[start2] == sum)
    {
      ans.push_back(make_pair(arr1[start1], arr2[start2]));
      start1++, start2++;
    }
    else if(arr1[start1] + arr2[start2] < sum)
    {
      start1++;
    }
    else
    {
      start2++;
    }
  }
  return ans;
}

int main()
{
  int arr1[] = {1, 2, 4, 5, 7};
  int arr2[] = {5, 6, 3, 4, 8};
  int n = sizeof(arr1) / sizeof(arr1[0]);
  int m = sizeof(arr2) / sizeof(arr2[0]);

  int sum = 9;

  vector<pair<int, int>> vp = allPairs(arr1, arr2, n, m, sum);

  int sz = vp.size();

  if(sz == 0)
  {
    cout<<-1<<endl;
  }
  else
  {
    for(int i = 0; i < sz; i++)
    {
      if(i == 0)
      {
        cout<<vp[i].first<<" "<<vp[i].second;
      }
      else
      {
        cout<<", "<<vp[i].first<<" "<<vp[i].second;
      }
      cout<<endl;
    }
  }

  return 0;
}
