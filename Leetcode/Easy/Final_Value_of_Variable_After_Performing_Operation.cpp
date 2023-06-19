#include<iostream>
#include<string>
#include<vector>
using namespace std;

int finalValueAfterOperations(vector<string>& operations)
{
  int ans = 0;
  for(int i = 0; i < operations.size(); i++)
  {
    if(operations.at(i) == "X++")
    {
      ans = ans + 1;
    }
    else if(operations.at(i) == "++X")
    {
      ans = ans + 1;
    }
    else if(operations.at(i) == "X--")
    {
      ans = ans - 1;
    }
    else if(operations.at(i) == "--X")
    {
      ans = ans - 1;
    }
  }

  return ans;
}

int main()
{
  vector<string> operations = {"X++","++X","--X","X--", "++X", "++X"};
  int ans = finalValueAfterOperations(operations);
  cout<<ans;
  return 0;
}
