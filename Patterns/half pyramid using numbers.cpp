#include<iostream>
using namespace std;

void pyramidnos(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<i;
        }
        cout<<endl;
    }
}

int main()
{
    cout<<"enter number"<<endl;
    int n;
    cin>>n;
    pyramidnos(n);
    return 0;
}

