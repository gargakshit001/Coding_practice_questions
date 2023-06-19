#include<iostream>
#include<vector>
using namespace std;

//Time Complexity: O(n); Space Complexity: O(n)
vector<int> concatenate(vector<int>& nums)
{
  int n = nums.size();
  vector<int> ans(2 * n);

  for(int i = 0; i < n; i++)
  {
    ans[i] = nums[i];
    ans[n + i] = nums[i];
  }
  return ans;
}

int main()
{
  vector<int> nums;
  vector<int> ans;
  int n;
  cin>>n;
  for(int i = 0; i < n; i++)
  {
    int a;
    cin>>a;
    nums.push_back(a);
  }
  for(int i = 0; i < nums.size(); i++)
  {
    cout<<nums.at(i)<<" ";
  }
  cout<<endl;

  ans = concatenate(nums);
  for(int i = 0; i < ans.size(); i++)
  {
    cout<<ans.at(i)<<" ";
  }
  cout<<endl;

  return 0;
}
