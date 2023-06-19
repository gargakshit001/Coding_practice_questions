#include<iostream>
using namespace std;

void pyramid(int n)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}

int main()
{
    cout<<"number "<<endl;
    int n;
    cin>>n;
    pyramid(n);
    return 0;
}
