#include<bits/stdc++.h>
using namespace std;

bool myCompare(string a, string b)
{
  return (a + b) > (b + a);
}

string printLargest(vector<string> &arr)
{
  sort(arr.begin(), arr.end(), myCompare);
  string res = "";
  for(auto s : arr)
  {
    res += s;
  }

  return res;
}

int main()
{
  vector<string> arr{"3", "30", "34", "5", "9"};

  cout<<printLargest(arr);

  return 0;
}
