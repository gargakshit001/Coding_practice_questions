#include<iostream>
#include<string>
using namespace std;

string defangIPaddr(string address)
{
  string ip = "";

  for(char c : address)
  {
    (c == '.') ? ip += "[.]" : ip += c;
  }

  return ip;
}

int main()
{
  string IP = "1.1.1.1.1.1.1.1";
  cout<<defangIPaddr(IP);
  return 0;
}
