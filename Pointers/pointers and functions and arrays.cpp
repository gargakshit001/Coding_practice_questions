#include<iostream>
using namespace std;

int sum(int* arr, int n)
{
    int s = 0;
    for(int i=0;i<n;i++)
    {
        s = s + *(arr+i);
        //another method
        //s = s + arr[i];
    }
    return s;
}

int main()
{
    int a[10];
    for(int i=0;i<10;i++)
    {
        cin>>a[i];
    }
    cout<<sum(a, 10)<<endl;
    return 0;
}
