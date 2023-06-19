#include<iostream>
using namespace std;

void numtree(int n)
{
    for(int i=1;i<=n;i++)
    {
        int space = n-i;
        for(int j=1;j<=space;j++)
        {
            cout<<" ";
        }
        for(int j=1;j<=i;j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    cout<<"enter number"<<endl;
    int n;
    cin>>n;
    numtree(n);
    return 0;
}
