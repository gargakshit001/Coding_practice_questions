#include<iostream>
using namespace std;
/*
void rotby1(int a[], int k)
{
    int temp0=a[0], j=0;
    for(int i=j;i<k;i++)
    {
        a[i]=a[i+1];
    }
    a[k-1]=temp0;
    j=j+k;
    k=k+k;
}

void rot(int a[], int k, int n)
{
    int k1=k-1;
    int j=0;
    for(int i=j;i<k1;i++)
    {
        rotby1(a, k);
    }
    j=j+k;
    k1=k1+k;
}

void reverse(int a[], int n, int k)
{
    if(k<=n)
    {
        rot(a, k, n);
    }
}*/

void reverse(int arr[], int n, int k)
{
    for (int i = 0; i < n; i=i+k)//i += k)
    {
        int left = i;

        // to handle case when k is not multiple of n
        int right = min(i + k - 1, n - 1);

        // reverse the sub-array [left, right]
        while (left < right)
            swap(arr[left++], arr[right--]);

    }
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
    reverse(arr, n, k);
    print(arr, n);
    return 0;
}
