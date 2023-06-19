#include<iostream>
using namespace std;

void rect(int a, int b)
{
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}

int main()
{
    cout<<"enter rows and columns"<<endl;
    int r,c;
    cin>>r>>c;
    rect(r,c);
    return 0;
}

