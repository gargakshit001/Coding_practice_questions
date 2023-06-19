#include<iostream>
using namespace std;

void hollowrect(int a, int b)
{
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            if(i==1||i==a||j==1||j==b)
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
    cout<<"enter rows and columns"<<endl;
    int r,c;
    cin>>r>>c;
    hollowrect(r,c);
    return 0;
}

