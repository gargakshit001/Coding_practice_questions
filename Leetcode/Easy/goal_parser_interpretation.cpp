#include<iostream>
#include<string>
using namespace std;

string interpret(string command)
{
  string ans;
  int n = command.length();
  int i = 0;

  while(i < n)
  {
    if(command[i] == 'G')
    {
      ans += 'G';
      i++;
    }
    else if(command[i + 1] == 'a')
    {
      ans += "al";
      i += 4;
    }
    else
    {
      ans += 'o';
      i += 2;
    }
  }
  return ans;
}

int main()
{
  string IP = "G()(al)";
  cout<<interpret(IP);
  return 0;
}
