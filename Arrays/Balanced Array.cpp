#include<iostream>
using namespace std;

int minValueToBalance(int a[], int n)
{
    int low=0;
    int high=n-1;
    int mid=(low+high)/2;
    int sum1=0, sum2=0;
    for(int i=low;i<mid+1;i++)
    {
        sum1=sum1+a[i];
    }
    for(int j=mid+1;j<=high;j++)
    {
        sum2=sum2+a[j];
    }
    int sum=sum1-sum2;
    return sum;
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
    cout<<"number to be added: "<<minValueToBalance(arr, n);
    return 0;
}
