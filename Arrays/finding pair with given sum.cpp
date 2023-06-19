#include<iostream>
using namespace std;

int fs(int arr[], int n, int sum)
{
    int count = 0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]+arr[j]==sum)
            {
                count++;
            }
        }
        return count;
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
    cout<<"enter the sum "<<endl;
    int s;
    cin>>s;
    int result = fs(arr,n,s);
    cout<<result;
    return 0;
}
