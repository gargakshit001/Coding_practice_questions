#include<bits/stdc++.h>
#include<iostream>
using namespace std;

string longestCommonPrefix (string arr[], int n)
{
  sort(arr, arr + n);

  int i = 0, j = 0;
  string str1 = arr[0], str2 = arr[n - 1];
  int a = str1.length(), b = str2.length();

  string ans = "";
  string res = "-1";

  while(i < a && j < b)
  {
    if(str1[i] == str2[j])
    {
      ans += str1[i];
      i++;
      j++;
    }
    else
    {
      break;
    }
  }

  if(ans.length() > 0)
  {
    return ans;
  }
  return res;
}

int main()
{
  string arr[] = {"geeksforgeeks", "geeks", "geek", "geezer"};
  int n = sizeof(arr) / sizeof(arr[0]);

  string ans = longestCommonPrefix(arr, n);
  cout<<ans;
}
