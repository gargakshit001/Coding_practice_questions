#include<iostream>
using namespace std;

void rotby1(int arr[],int n)
{
    int temp=arr[0];
    for(int i=0;i<n;i++)
        {
            arr[i]=arr[i+1];
        }
    arr[n-1]=temp;
}

void rot(int arr[],int d, int n)
{
    for(int i=0;i<d;i++)
    {
        rotby1(arr, n);
    }
}

void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}


int main()
{
    cout<<"Enter array size "<<endl;
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter array elements "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"enter the element of rotation "<<endl;
    int r;
    cin>>r;
    rot(a, r, n);
    print(a, n);

    return 0;
}

