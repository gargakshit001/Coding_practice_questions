#include<iostream>
using namespace std;


//using iterative method
void fibonacci(int n)
{
    int t1 = 0;
    int t2 = 1;
    int t3;
    for(int i=0;i<n;i++)
    {
        cout<<t1<<" ";
        t3=t2+t1;
        t1=t2;
        t2=t3;
    }

}

//using recursion
int rec_fibonacci(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    int smalloutput = rec_fibonacci(n-1) + rec_fibonacci(n-2);
    return smalloutput;
}

int Fibonacci2(int n, int *ans)
{
    if(n <= 1)
    {
        ans[n] = n;
        return n;
    }

    if(ans[n-1] == 0)
    {
        ans[n-1] = Fibonacci2(n - 1, ans);
    }

    if(ans[n-2] == 0)
    {
        ans[n-2] == Fibonacci2(n - 2, ans);
    }

    ans[n] = ans[n-1] + ans[n-2];
    return ans[n];
}

int fibonacci2(int n)
{
    int *ans = new int[n+1];
    for(int i = 0; i <= n; i++)
    {
        ans[i] = 0;
    }

    return Fibonacci2(n, ans);
}

int fibonacci3(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = 1;

    for(int i = 2; i <= n; i++)
    {
        ans[i] = ans[i - 1] + ans[i - 2];
    }

    return ans[n];
}

int main()
{
    int n;
    cout<<"Enter the number "<<endl;
    cin>>n;

    fibonacci(n);
    cout<<endl<<rec_fibonacci(n)<<endl;
    cout<<fibonacci2(n)<<endl;
    cout<<fibonacci3(n)<<endl;

    return 0;
}
