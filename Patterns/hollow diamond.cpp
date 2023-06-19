#include<iostream>
using namespace std;

void hollowdiamond(int n)
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
            if(j>1 && j<=i)
            {
                cout<<" ";
            }
            else
            {
                cout<<"*";
            }
        }
        for(int j=2;j<=i;j++)
        {
            if(j>=2 && j<i)
            {
                cout<<" ";
            }
            else
            {
                cout<<"*";
            }
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
            if(j>1 && j<=i)
            {
                cout<<" ";
            }
            else
            {
                cout<<"*";
            }
        }
        for(int j=2;j<=i;j++)
        {
            if(j>=2 && j<i)
            {
                cout<<" ";
            }
            else
            {
                cout<<"*";
            }
        }
        cout<<endl;
    }
}

int main()
{
    cout<<"enter number"<<endl;
    int n;
    cin>>n;
    hollowdiamond(n);
    return 0;
}
