#include<iostream>
#include<climits>
using namespace std;

void rotby1(int a[], int n)
{
    int temp=a[0];
    for(int i=0;i<n;i++)
    {
        a[i]=a[i+1];
    }
    a[n-1]=temp;
}

void rot(int a[], int r, int n)
{
    for(int i=0;i<r;i++)
    {
        rotby1(a, n);
    }
}

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

void min_ele(int a[], int n)
{
    int min_num=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(a[i]<min_num)
        {
            min_num=a[i];
        }
    }
    cout<<min_num;
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
    cout<<"enter number of elements "<<endl;
    int n;
    cin>>n;
    cout<<"enter array elements "<<endl;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    print(arr, n);
    cout<<"Sorted array: ";
    sort(arr, n);
    print(arr, n);
    cout<<"enter number of rotations "<<endl;
    int r;
    cin>>r;
    cout<<"rotated array: ";
    rot(arr, r, n);
    print(arr, n);
    //min_ele(arr, n);
    cout<<"min element in rotated array: ";
    min_ele(arr, n);
    return 0;

}
