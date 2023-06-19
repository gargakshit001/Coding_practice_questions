#include<bits/stdc++.h>
#include<iostream>
using namespace std;

string value(char ch)
{
  string arr[] = { "2",   "22",  "222", "3",   "33",   "333", "4",
            "44",  "444", "5",   "55",  "555",  "6",   "66",
            "666", "7",   "77",  "777", "7777", "8",   "88",
            "888", "9",   "99",  "999", "9999" };

  return arr[ch - 'A'];
}

string printSequence(string str)
{
  string ans = "";

  for(int i = 0; i < str.length(); i++)
  {
    if(str[i] == ' ')
    {
      ans += "0";
    }
    else
    {
      ans += value(str[i]);
    }
  }

  return ans;
}

int main()
{
  string input = "GEEKSFORGEEKS";
  cout << printSequence(input);

  return 0;
}
