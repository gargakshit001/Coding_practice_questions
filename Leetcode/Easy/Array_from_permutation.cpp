//Given a zero-based permutation nums (0-indexed), build an array ans of the same length
//where ans[i] = nums[nums[i]] for each 0 <= i < nums.length and return it.

#include<iostream>
#include<vector>
using namespace std;

//Time Complexity: O(n); Space Complexity: O(n)
vector<int> buildArray(vector<int>& nums)
{
  int n = nums.size();
  vector<int> ans(n);

  for(int i = 0; i < n; i++)
  {
    ans[i] = nums[nums[i]];
  }
  return ans;
}

//Time Complexity: O(n); Space Complexity: O(1)
vector<int> buildArray1(vector<int>& nums)
{
  int n=nums.size();
  for(int i=0;i<n;i++)
  {
    nums[i]=nums[i]+(n*(nums[nums[i]]%n));
  }
  for(int i=0;i<n;i++)
  {
    nums[i]/=n;
  }
  return nums;
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

  ans = buildArray1(nums);
  for(int i = 0; i < ans.size(); i++)
  {
    cout<<ans.at(i)<<" ";
  }
  cout<<endl;

  return 0;
}
