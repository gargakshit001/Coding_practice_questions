#include<iostream>
using namespace std;

int count(int a[], int n, int x)
{
    int index=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==x)
        {
            index++;
        }
    }
    return index;

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
    cout<<"number of occurence of "<<k<<": "<<count(arr, n, k);
    return 0;
}
