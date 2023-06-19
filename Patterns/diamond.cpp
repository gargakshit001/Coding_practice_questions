#include<iostream>
using namespace std;

void diamond(int n)
{
    for(int i=1;i<=n;i++)
    {
        int space=n-i;
        for(int j=1;j<=space;j++)
        {
            cout<<" ";
        }
        for(int j=1;j<=i;j++)
        {
            cout<<"*";
        }
        for(int j=2;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=n;i>=1;i--)
    {
        int space=n-i;
        for(int j=1;j<=space;j++)
        {
            cout<<" ";
        }
        for(int j=1;j<=i;j++)
        {
            cout<<"*";
        }
        for(int j=2;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}

int main()
{
    cout<<"enter number"<<endl;
    int n;
    cin>>n;
    diamond(n);
    return 0;
}
