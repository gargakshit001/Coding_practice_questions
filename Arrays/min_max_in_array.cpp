#include <iostream>
#include<climits>
using namespace std;

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
    int max_num, min_num;
    //cout<<endl<<arr[0]<<endl;
    max_num=INT_MIN;
    min_num=INT_MAX;
    for(int j=0;j<n;j++)
    {
        if(max_num<arr[j])
        {
            max_num=arr[j];
        }
    }
    for(int j=0;j<n;j++)
    {
        if(min_num>arr[j])
        {
            min_num=arr[j];
        }
    }
    cout<<endl<<"Largest element: "<<max_num<<endl;
    cout<<"Smallest element: "<<min_num<<endl;
    return 0;
}
