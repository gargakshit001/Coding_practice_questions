#include<iostream>
using namespace std;

int index(int a[], int n, int key)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            return i;
            break;
        }
    }
    return -1;
}

int minDist(int a[], int n, int x, int y)
{
    int x1=index(a, n, x);
    int x2=index(a, n, y);
    int dif=x2-x1;
    if(x1==-1 || x2==-1)
    {
        return -1;
    }
    return dif;
}

void print(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<< " ";
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
    cout<<"enter the 2 elements "<<endl;
    int a, b;
    cin>>a>>b;
    cout<<"difference between indices is: "<<minDist(arr, n, a, b);

    return 0;
}
