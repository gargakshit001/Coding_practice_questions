#include<iostream>
using namespace std;

void rhombus(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=2*n - 1;j++)
        {
            if((i+j)<=n || (i+j)>=2*n + 1)
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
    rhombus(n);
    return 0;
}

