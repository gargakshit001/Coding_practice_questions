#include<iostream>
using namespace std;
int main()
{
    int i = 10;
    int* p= &i;
    cout<<p<<endl<<sizeof(p)<<endl;
    //this just adds 4 bits to p
    p = p + 1;
    cout<<p;
    return 0;
}
