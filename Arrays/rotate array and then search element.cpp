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

void print(int a[], int n)
{
    for(int i=0;i<n; i++)
    {
        cout<<a[i]<<" ";
    }
}

void fs(int a[], int key, int n)
{
    int index=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            cout<<"element searched: "<<a[i]<<endl<<"present at index: "<<index<<endl;
        }
        else
        {
            index++;
        }
    }
    return ;
}

int main()
{
    cout<<"enter array size "<<endl;
    int n;
    cin>>n;
    int arr[n];
    cout<<"enter elements "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    print(arr, n);
    cout<<endl;
    cout<<"enter the number of rotations "<<endl;
    int r;
    cin>>r;
    rot(arr, r, n);
    print(arr, n);
    cout<<endl;
    cout<<"enter the search element "<<endl;
    int s;
    cin>>s;
    fs(arr, s, n);
    return 0;
}

