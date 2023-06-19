#include<iostream>
#include<string>
using namespace std;

//Brute Force Method
int lcs(string s, string t)
{
  //Base Case
  if(s.length() == 0 || t.length() == 0)
  {
    return 0;
  }

  //Recursive Calls
  if(s[0] == t[0])
  {
    return 1 + lcs(s.substr(1), t.substr(1));
  }

  else
  {
    int x = lcs(s.substr(1), t);
    int y = lcs(s, t.substr(1));
    return max(x, y);
  }
}

//Memorization Method
int lcs_betterHelper(string s, string t, int** ans)
{
  if(s.length() == 0 || t.length() == 0)
  {
    return 0;
  }

  int m = s.length();
  int n = t.length();

  if(ans[m][n] != -1)
  {
    return ans[m][n];
  }

  if(s[0] == t[0])
  {
    ans[m - 1][n - 1] = lcs_betterHelper(s.substr(1), t.substr(1), ans);
    ans[m][n] = 1 + ans[m - 1][n - 1];
  }

  else
  {
    ans[m - 1][n] = lcs_betterHelper(s.substr(1), t, ans);
    ans[m][n - 1] = lcs_betterHelper(s, t.substr(1), ans);
    ans[m][n] = max(ans[m - 1][n], ans[m][n - 1]);
  }

  return ans[m][n];
}

int lcs_better(string s, string t)
{
  int m = s.length();
  int n = t.length();

  int** ans = new int*[m + 1];
  for(int i = 0; i <= m; i++)
  {
    ans[i] = new int[n + 1];
  }

  for(int i = 0; i <= m; i++)
  {
    for(int j = 0; j <= n; j++)
    {
      ans[i][j] = -1;
    }
  }

  return lcs_betterHelper(s, t, ans);
}

//DP Method
int lcs_dp(string s, string t)
{
  int m = s.length();
  int n = t.length();

  int** ans = new int*[m + 1];
  for(int i = 0; i <= m; i++)
  {
    ans[i] = new int[n + 1];
  }

  //For 1st Row
  for(int i = 0; i <= n; i++)
  {
    ans[0][i] = 0;
  }

  //For 1st Column
  for(int i = 0; i <= m; i++)
  {
    ans[i][0] = 0;
  }

  for(int i = 1; i <= m; i++)
  {
    for(int j = 1; j <= n; j++)
    {
      if(s[m - i] == t[n - j])
      {
        ans[i][j] = 1 + ans[i - 1][j - 1];
      }

      else
      {
        ans[i][j] = max(ans[i - 1][j], ans[i][j - 1]);
      }
    }
  }

  return ans[m][n];
}

int main()
{
  string s, t;
  cin>>s>>t;

  cout<<"Largest common substring: "<<lcs(s, t)<<endl;
  cout<<"Largest common substring: "<<lcs_better(s, t)<<endl;
  cout<<"Largest common substring: "<<lcs_dp(s, t)<<endl;
}
