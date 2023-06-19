#include<iostream>
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

void rot(int a[], int d, int n)
{
    for(int i=0;i<d;i++)
    {
        rotby1(a, n);
    }
}

int fr(int a[],int x, int n)
{
    int index=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==x)
        {
            return index;
        }
        else
        {
            index++;
        }
    }

}

void sort(int a[], int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            {
                if(a[j]<a[i])
                {
                    int temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
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
    cout<<"enter number of elements "<<endl;
    int n;
    cin>>n;
    cout<<"enter elements of array "<<endl;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    print(arr, n);
    cout<<"Sorted array: ";
    sort(arr, n);
    print(arr, n);
    int le=arr[n-1];
    cout<<"enter number of rotations "<<endl;
    int r;
    cin>>r;
    rot(arr, r, n);
    print(arr, n);
    int ind=fr(arr, le, n-1);
    cout<<"number of rotations made: "<<n-1-ind;

    return 0;
}
