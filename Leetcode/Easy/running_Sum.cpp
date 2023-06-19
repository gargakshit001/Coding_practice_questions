#include<iostream>
#include<vector>
using namespace std;

vector<int> runningSum(vector<int> &nums)
{
  vector<int> ans(nums.size());

  ans[0] = nums[0];

  for(int i = 1; i < nums.size(); i++)
  {
    ans[i] = ans[i - 1] + nums[i];
  }

  return ans;
}

int main()
{
  vector<int> s = {1, 2, 3, 4, 5};
  vector<int> ans = runningSum(s);
  for(int i = 0; i < s.size(); i++)
  {
    cout<<ans.at(i)<<" ";
  }

  return 0;
}
