#include<iostream>
using namespace std;

int main()
{
    int i = 10;
    int *p = &i;
    int** p2 = &p;
    cout<<"&i: "<<&i<<endl;
    cout<<"p: "<<p<<endl;
    cout<<"*p2: "<<*p2<<endl;
    cout<<"&p: "<<&p<<endl;
    cout<<"p2: "<<p2<<endl;
    cout<<"i: "<<i<<endl;
    cout<<"*p: "<<*p<<endl;
    cout<<"**p2: "<<**p2<<endl;
    return 0;
}
