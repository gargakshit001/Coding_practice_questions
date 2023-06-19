#include<iostream>
using namespace std;

void zigzag(int n)
{
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if((i+j)%4==0)
            {
                cout<<"*";
            }
            else if(i==2 && j%4==0)
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
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
    zigzag(n);
    return 0;
}
