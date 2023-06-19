#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool isRotated(string str1, string str2)
{
  bool clockwise = true, anticlockwise = true;

  if(str1.length() != str2.length())
  {
    return false;
  }

  int n = str1.length();
  for(int i = 0; i < n; i++)
  {
    if(str1[i] != str2[(i + 2) % n])
    {
      clockwise = false;
      break;
    }
  }
  for(int i = 0; i < n; i++)
  {
    if(str1[(i + 2) % n] != str2[i])
    {
      anticlockwise = false;
      break;
    }
  }

  return clockwise or anticlockwise;
}

int main()
{
  string str1 = "amazon";
  string str2 = "azonam";
  cout<<str1<<" "<<str2<<endl;

  bool ans = isRotated(str1, str2);

  if(ans == 1)
  {
    cout<<"YES";
  }
  else
  {
    cout<<"NO";
  }

  return 0;
}
