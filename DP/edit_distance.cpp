#include<iostream>
#include<string>
using namespace std;

//Brute Force Method
int ed(string s, string t)
{
  //Base Case
  if(s.length() == 0 || t.length() == 0)
  {
    return max(s.length(), t.length());
  }

  //Recursive Calls
  if(s[0] == t[0])
  {
    return ed(s.substr(1), t.substr(1));
  }

  else
  {
    int x = ed(s.substr(1), t);
    int y = ed(s, t.substr(1));
    int z = ed(s.substr(1), t.substr(1));

    return 1 + min(x, min(y, z));
  }
}

//Memorization Method
int ed_betterHelper(string s, string t, int** ans)
{
  if(s.length() == 0 || t.length() == 0)
  {
    return max(s.length(), t.length());
  }

  int m = s.length();
  int n = t.length();

  if(ans[m][n] != -1)
  {
    return ans[m][n];
  }

  if(s[0] == t[0])
  {
    ans[m][n] = ed_betterHelper(s.substr(1), t.substr(1), ans);
  }

  else
  {
    ans[m - 1][n] = ed_betterHelper(s.substr(1), t, ans);
    ans[m][n - 1] = ed_betterHelper(s, t.substr(1), ans);
    ans[m - 1][n - 1] = ed_betterHelper(s.substr(1), t.substr(1), ans);

    ans[m][n] = 1 + min(ans[m - 1][n], min(ans[m][n - 1], ans[m - 1][n - 1]));
  }

  return ans[m][n];
}

int ed_better(string s, string t)
{
  int m = s.length();
  int n = t.length();

  int** ans = new int* [m + 1];
  for(int i = 0; i <= m; i++)
  {
    ans[i] = new int[n];
  }

  for(int i = 0; i <= m; i++)
  {
    for(int j = 0; j <= n; j++)
    {
      ans[i][j] = -1;
    }
  }

  return ed_betterHelper(s, t, ans);
}

//DP Method
int ed_DP(string s, string t)
{
  int m = s.length();
  int n = t.length();

  int** ans = new int* [m + 1];
  for(int i = 0; i <= m; i++)
  {
    ans[i] = new int[n];
  }

  //For 1st Row
  for(int i = 0; i <= n; i++)
  {
    ans[0][i] = i;
  }

  //For 1st Row
  for(int i = 0; i <= m; i++)
  {
    ans[i][0] = i;
  }

  for(int i = 1; i <= m; i++)
  {
    for(int j = 1; j <= n; j++)
    {
      if(s[m - i] == t[n - j])
      {
        ans[i][j] = ans[i - 1][j - 1];
      }

      else
      {
        ans[i][j] = 1 + min(ans[i][j - 1], min(ans[i - 1][j], ans[i - 1][j - 1]));
      }
    }
  }

  return ans[m][n];
}

int main()
{
  string s, t;
  cin>>s>>t;

  cout<<"Minimum Count: "<<ed(s, t)<<endl;
  cout<<"Minimum Count: "<<ed_better(s, t)<<endl;
  cout<<"Minimum Count: "<<ed_DP(s, t)<<endl;

  return 0;
}
