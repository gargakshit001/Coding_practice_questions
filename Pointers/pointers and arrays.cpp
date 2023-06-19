#include<iostream>
using namespace std;
int main()
{
    int a[10];
    //this gives the same output
    cout<<a<<endl;
    cout<<&a[0]<<endl;

    a[0]=5;
    a[1]=10;
    cout<<*a<<endl;
    //*(a+1) is same as a[1]
    //or we can say that *(a+i) is same as [a+i]
    cout<<*(a+1)<<endl;
    cout<<a[1]<<endl;

    //size of array is (4*no of elements) but size of pointer is always 4 (or 8)
    //because for a pointer, a 4 byte memory is allocated whereas no memory is allocated for an array
    cout<<sizeof(a)<<endl;
    cout<<sizeof(*(a+10))<<endl;

    //this gives the same output as no memory is allocated for an array
    cout<<a<<endl;
    cout<<&a<<endl;
    return 0;
}
