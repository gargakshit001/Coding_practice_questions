#include<iostream>
using namespace std;

void increment(int &n)
{
    n++;
}

int main()
{
    int i = 10;
    int& j = i;   //reference variable has to be initialized otherwise it'll give an error
    cout<<i<<endl<<j<<endl;

    i++;
    cout<<j<<endl;
    j++;
    cout<<i<<endl;
    increment(i);
    cout<<i<<endl;

    int k = 100;
    j=k;
    cout<<j<<endl;
    return 0;
}
