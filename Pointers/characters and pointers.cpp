#include<iostream>
using namespace std;
int main()
{
    int a[]={1,2,3};
    char b[]= "abc";
    cout<<a<<endl;
    cout<<b<<endl;

    //this does not print the address of first character but prints the whole set of characters
    char* c = &b[0];
    cout<<c<<endl;

    char c1 = 'a';
    char* pc = &c1;
    cout<<c1<<endl;
    //this prints the string until it finds a null character
    cout<<pc<<endl;
    return 0;
}
