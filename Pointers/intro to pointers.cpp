#include<iostream>
using namespace std;
int main()
{
    int i = 10;
    cout<<i<<endl<<&i;
    int *p=&i;
    cout<<endl;
    cout<<p<<endl<<*p<<endl;
    cout<<sizeof(p);
    return 0;
}
