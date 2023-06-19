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

void max_pro(int a[], int n)
{
    cout<<"max product: "<<a[n-1]*a[n-2]<<endl;
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
    cout<<"enter test cases "<<endl;
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cout<<"enter the array size "<<endl;
        int n;
        cin>>n;
        cout<<"enter the elements "<<endl;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<"user array: ";
        print(arr, n);
        sort(arr, n);
        max_pro(arr, n);
    }

    return 0;
}
