//Program to remove vowels from a String

#include<iostream>
#include<string>
#include<vector>
using namespace std;

string removeVowel(string str)
{
  int n = str.length();
  for(int i = 0; i < n; i++)
  {
    if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
    {
      str = str.replace(i, 1, " ");
    }
  }
  return str;
}

int main()
{
  string s;
  getline(cin, s); //To take input from the user
  //s = "To become a good coder";
  cout<<s<<endl;
  cout<<removeVowel(s);

  return 0;
}
