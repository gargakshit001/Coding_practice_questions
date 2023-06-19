#include <iostream>
#include<climits>
using namespace std;

int search(int array[], int n, int key)
{
    for(int j=0;j<n;j++)
    {
        if(key==array[j])
        {
            return j;
        }
    }
    return -1;
}

int main()
{
    int n;
    cout<<"Enter array size "<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter array elements "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    int key;
    cout<<endl<<"Enter the key "<<endl;
    cin>>key;
    cout<<search(arr,n,key);
    return 0;
}
