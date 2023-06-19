#include<iostream>
using namespace std;

void invertedpattern(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=n;j>=i;j--)
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
    invertedpattern(n);
    return 0;
}

