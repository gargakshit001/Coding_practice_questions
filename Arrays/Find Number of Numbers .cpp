#include<iostream>
using namespace std;

int num(int a[], int n, int k)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        while(a[i]>0)
        {
            if(a[i]%10==k)
                count++;
            a[i]=a[i]/10;
        }
    }
    return count;
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
    cout<<"enter key: "<<endl;
    int k;
    cin>>k;
    cout<<"number of times "<<k<<" appears: "<<num(arr, n, k);
    return 0;
}
