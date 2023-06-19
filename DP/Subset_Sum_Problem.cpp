#include<bits/stdc++.h>
using namespace std;

bool isSubsetSum(int arr[], int n, int sum)
{
  int dp[sum + 1];

	// Initializing with 1 as sum 0 is
	// always possible
	dp[0] = 1;

	// Loop to go through every element of
	// the elements array
	for(int i = 0; i < n; i++)
	{
		// To change the values of all possible sum
		// values to 1
		for(int j = sum; j >= arr[i]; j--)
		{
			if (dp[j - arr[i]] == 1)
      {
        dp[j] = 1;
      }
		}
	}

	// If sum is possible then return 1
	if (dp[sum] == 1)
  {
    return true;
  }

	return false;
}

int main()
{
  int arr[] = {2, 3, 5};
  int sum = 3;

  int n = sizeof(arr) / sizeof(arr[0]);

  if(isSubsetSum(arr, n, sum) == true)
  {
    cout <<"Found a subset with given sum";
  }
  else
  {
    cout <<"No subset with given sum";
  }

  return 0;
}
