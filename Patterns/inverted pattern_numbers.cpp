#include<iostream>
using namespace std;

void inverted(int n)
{
    int count=1;

    for(int i=n;i>=1;i--)
    {
        count = 1;
        for(int j=1;j<=i;j++)
        {
            cout<<count<<" ";
            count++;
        }
        cout<<endl;
    }
}

int main()
{
    cout<<"enter number"<<endl;
    int n;
    cin>>n;
    inverted(n);
    return 0;
}

