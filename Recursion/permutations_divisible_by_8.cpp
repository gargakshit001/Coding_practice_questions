#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

void solve(int index, string s, vector<string> ans)
{
  if(index == s.length())
  {
    ans.push_back(s);
    return;
  }

  for(int i = index; i < s.length(); i++)
  {
    if(i > index && s[i] == s[i - 1])
    {
      continue;
    }

    swap(s[i], s[index]);
    solve(index + 1, s, ans);
    swap(s[i], s[index]);
  }
}

vector<string> find_permutations(string s)
{
  vector<string> ans;

  sort(s.begin(), s.end());

  solve(0, s, ans);

  return ans;

}

void find_permutations_2(string s,string up){

  vector<string> ans;
  //string res = "NO";
  if(s.length()==0){
    cout<<up<<endl;

    /*int tl = up.length();

    int n = (tl < 3) ? stoi(up) : stoi(up.substr(tl - 3, 3));

    if(n % 8 == 0)
    {
      cout<<"YES"<<endl;
      return;
    }
    else
    {
      cout<<"NO"<<endl;
      return;
    }*/
  }

  for(int i=0;i<s.length();i++){
    find_permutations_2(s.substr(0,i)+s.substr(i+1),up+s[i]);
  }

}

string DivisibleByEight(vector<string> arr)
{
  string ans = "NO";

  for(int i = 0; i < arr.size(); i++)
  {
    string s = arr[i];
    cout<<s<<endl;

    int tl = s.length();
    int n = (tl < 3) ? stoi(s) : stoi(s.substr(tl - 3, 3));

    if(n % 8 == 0)
    {
      ans = "YES";
      return ans;
    }
  }

  return ans;
}

vector<string> checkDivisibility(vector<string> arr)
{
  vector<string> ans;

  for(int i = 0; i < arr.size(); i++)
  {
    vector<string> permutations = find_permutations(arr[i]);
    string res = DivisibleByEight(permutations);
    ans.push_back(res);
  }

  return ans;
}

int main()
{
  vector<string> arr = {"123", "61"};
  find_permutations_2("123","");
  // vector<string> ans = checkDivisibility(arr);
  // for(auto i : ans)
  // {
  //   cout<<i<<endl;
  // }

  return 0;
}
