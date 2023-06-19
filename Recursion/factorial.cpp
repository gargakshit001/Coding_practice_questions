#include<iostream>
using namespace std;

int factorial(int n)
{
    int smalloutput = 1;
    if(n==1)
    {
        return 1;
    }
    smalloutput = n * factorial(n-1);
    return smalloutput;

}

int main()
{
    int n;
    cin>>n;
    cout<<factorial(n);
    return 0;
}
