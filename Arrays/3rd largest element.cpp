#include<iostream>
using namespace std;

void sort(int a[], int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
    {
        if(a[i]>a[j])
        {
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
}

void thlarge(int a[], int n)
{
    cout<<"third largest element: "<<a[n-3];
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
    sort(arr, n);
    cout<<"sorted array: ";
    print(arr, n);
    thlarge(arr, n);
    return 0;
}
