#include<bits/stdc++.h>
#include<iostream>
using namespace std;

string smallestWindow(string s, string p)
{
  if(p.length() > s.length())
  {
    return "-1";  //if size of p is greater than n then return -1
  }

  int ans = INT_MAX;  //length of the ans string
  int count = 0;  //isliye bnaya h taki baar baar map me jaa
  //k element ki frequency na dekhni pde
  int start = 0;  //start of the ans string
  int m[256] = {0}; //to store the occurence of characters in string p

  for(int i = 0; i < p.length(); i++)
  {
    if(m[p[i]] == 0)
    {
      count++;
    }
    m[p[i]]++;
  }

  int i = 0;  //start of the window
  int j = 0;  //end of the window
  while(j < s.length())
  {
    m[s[j]]--;
    if(m[s[j]] == 0)  //jab b mera element map me zero hoga tb tb count--
    {
      count--;
    }

    if(count == 0)  //agr count zero h mtlb ki mere sare elements mil chuke h mujhe
    {
      while(count == 0)
      {
        if(ans > j - i + 1)
        {
          ans = min(ans, j - i + 1);  //updating length
          start = i;  //updating new start
        }
        m[s[i]]++;  //jo elements repeat ho rahe h unki frequency minus
        //me chli gai hogi to m unhe remove ya neglect kr sakta hu

        if(m[s[i]] > 0) //jase frequency 0 se jyada hui mtlb ki
        //mujhe us elemnt ki ab jroort h to count++
        {
          count++;
        }
        i++;
      }
    }
    j++;
  }

  if(ans != INT_MAX)
  {
    return s.substr(start, ans);
  }
  else
  {
    return "-1";
  }
}

int main()
{
  string s = "ADOBECODEBANC";
  string t = "ABC";
  cout<<"-->Smallest window that contain all character : "<<endl;
  cout << smallestWindow(s, t);

  return 0;
}
