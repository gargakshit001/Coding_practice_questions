#include<iostream>
using namespace std;

int main()
{
    int* p = new int;
    *p = 10;
    cout<<p<<endl<<&p<<endl;
    cout<<*p<<endl;

    int* pa = new int[50];
    int n;
    cin>>n;
    int* pa2 = new int[n];
    for(int i = 0; i<n ; i++)
    {
        cin>>pa2[i];
    }
    int max = -1;
    for(int i = 0;i<n;i++)
    {
        if(pa2[i]>max)
        {
            max = pa2[i];
        }
    }
    cout<<max<<endl;
    return 0;
}
