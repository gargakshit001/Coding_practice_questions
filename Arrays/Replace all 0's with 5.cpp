#include<iostream>
using namespace std;

int rev(int x)
{
    int rev_num=0;
    while(x>0)
    {
        int a=x%10;
        rev_num=(rev_num*10)+a;
        x=x/10;
    }
    return rev_num;
}

int convertFive(int n)
{
    if(n==0)
        return 5;

    int x=0;
    for(int i=0;i<n;i++)
    {
        while(n>0)
        {
            int a=n%10;
            if(a==0)
            {
                x=(x*10)+a+5;
            }
            else
            {
                x=x*10+a;
            }
            n=n/10;
        }
    }
    int ans = rev(x);
    return ans;
}


int main()
{
    cout<<"enter number "<<endl;
    int n;
    cin>>n;
    cout<<convertFive(n);

    return 0;
}
