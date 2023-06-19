#include<iostream>
using namespace std;

void floydtriangle(int n)
{
    int count = 1;
    for(int i=1;i<=n;i++)
    {
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
    floydtriangle(n);
    return 0;
}
