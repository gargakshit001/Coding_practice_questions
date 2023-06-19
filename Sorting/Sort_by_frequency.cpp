#include<bits/stdc++.h>
#include<iostream>
using namespace std;

pair<int, int> findEntryWithLargestValue(map<int, int> mp)
{
  pair<int, int> entryWithMaxValue =  make_pair(0, 0);

  map<int, int>::iterator itr;
  for(itr = mp.begin(); itr != mp.end(); ++itr)
  {
    if(itr->second > entryWithMaxValue.second)
    {
      entryWithMaxValue = make_pair(itr->first, itr->second);
    }
  }

  return entryWithMaxValue;
}

void SortbyFrequency(vector<int> arr)
{
  map<int, int> mp;
  int n = arr.size();
  for(int i = 0; i < n; i++)
  {
    mp[arr[i]]++;
  }

  map<int, int>::iterator itr;
  for(itr = mp.begin(); itr != mp.end(); ++itr)
  {
    cout<<itr->first<<" = "<<itr->second<<endl;
  }

  while(mp.size() != 0)
  {
    pair<int, int> MaxValue = findEntryWithLargestValue(mp);
    int num = MaxValue.first;

    while(mp[num] != 0)
    {
      cout<<num<<" ";
      mp[num]--;
    }
    mp.erase(num);
  }
  cout<<endl;
}

int main()
{
  vector<int> arr = {2, 5, 2, 8, 5, 6, 8, 8, 2, 6};
  int n = arr.size();
  for(int i = 0; i < n; i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;

  SortbyFrequency(arr);

  return 0;
}
