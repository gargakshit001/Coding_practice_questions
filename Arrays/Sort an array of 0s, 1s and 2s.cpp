#include<iostream>
using namespace std;

void sort012(int a[], int n)
{
    int count0=0,count1=0,count2=0;
    int i=0;
    for(int j=0;j<n;j++)
    {
        if(a[j]==0)
            count0++;
        if(a[j]==1)
            count1++;
        if(a[j]==2)
            count2++;
    }
    for(int j=0;j<count0;j++)
    {
        a[i]=0;
        i++;
    }
    for(int j=0;j<count1;j++)
    {
        a[i]=1;
        i++;
    }
    for(int j=0;j<count2;j++)
    {
        a[i]=2;
        i++;
    }
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
    int arr[n], i;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(i=0;i<n;i++)
    {
        if(arr[i]==0 || arr[i]==1 || arr[i]==2)
        {
            cout<<"sorted array: ";
            sort012(arr, n);
            break;
        }
        else
        {
            cout<<"Invalid Input "<<endl;
            break;
        }
    }

    return 0;
}
