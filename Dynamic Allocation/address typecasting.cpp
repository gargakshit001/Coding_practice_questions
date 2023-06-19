#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int i = 65;
    char c = i;   //this is implicit typecasting
    cout<<i<<endl<<c<<endl;

    int *p = &i;
    char *pc = (char*)p;   //this is explicit typecasting

    cout<<p<<endl<<pc<<endl;

    cout<<*p<<endl;
    cout<<*pc<<endl;
    cout<<*pc + 1<<endl;
    cout<<*(pc + 1)<<endl;
    cout<<*pc + 2<<endl;
    cout<<*(pc + 2)<<endl;
    cout<<*pc + 3<<endl;
    cout<<*(pc + 3)<<endl;
    return 0;
}
