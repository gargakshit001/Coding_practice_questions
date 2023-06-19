#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> shuffle(vector<int>& nums, int n)
{
  vector<int> shuffled(2 * n);
  for(int i = 0; i < n; i++)
  {
    shuffled[2 * i] = nums[i];
  }
  for(int j = 0; j < n; j++)
  {
    shuffled[(2 * j) + 1] = nums[n + j];
  }
  return shuffled;
}

int main()
{
  vector<int> nums = {1, 2, 3, 4, 5, 6};

  vector<int> shuffled = shuffle(nums, (nums.size() / 2));
  for(int i = 0; i < shuffled.size(); i++)
  {
    cout<<shuffled.at(i)<<" ";
  }

  return 0;
}
