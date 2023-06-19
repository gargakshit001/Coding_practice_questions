#include<iostream>
using namespace std;

void startree(int n)
{
    for(int i=1;i<=n;i++)
    {
        int space = n-i;
        for(int j=1;j<=space;j++)
        {
            cout<<"  ";
        }
        for(int j=i;j>=1;j--)
        {
            cout<<"*"<<" ";
        }
        for(int j=2;j<=i;j++)
        {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    for(int i=n;i>=1;i--)
    {
        int space = n-i;
        for(int j=1;j<=space;j++)
        {
            cout<<"  ";
        }
        for(int j=i;j>=1;j--)
        {
            cout<<"*"<<" ";
        }
        for(int j=2;j<=i;j++)
        {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    cout<<"enter number"<<endl;
    int n;
    cin>>n;
    startree(n);
    return 0;
}

