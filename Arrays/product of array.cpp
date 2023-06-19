#include<iostream>
using namespace std;

int product(int a[], int n)
{
    int pro=1;
    for(int i=0;i<n;i++)
    {
        pro=pro*a[i];
    }
    return pro;
}

void print(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    cout<<"enter array size "<<endl;
    int n;
    cin>>n;
    cout<<"enter array elements "<<endl;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    print(arr, n);
    cout<<"product of array is: "<<product(arr, n)<<endl;
    return 0;
}
