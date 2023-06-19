#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> removeDuplicates(int* a, int n)
{
  vector<int> output;
  unordered_map<int, bool> seen;

  for(int i = 0; i < n; i++)
  {
    if(seen.count(a[i]) > 0)
    {
      continue;
    }
    seen[a[i]] = true;
    output.push_back(a[i]);
  }

  return output;
}

int main()
{
  int a[] = {1, 2, 3, 2, 5, 4, 1, 3, 5, 2, 2, 1, 3};
  int n = sizeof(a)/sizeof(a[0]);
  vector<int> output = removeDuplicates(a, n);

  for(int i = 0; i < output.size(); i++)
  {
    cout<<output[i]<<endl;
  }

  return 0;
}
