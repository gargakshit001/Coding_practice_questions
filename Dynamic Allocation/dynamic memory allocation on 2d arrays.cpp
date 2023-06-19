#include<iostream>
using namespace std;
int main()
{
    int n, m;
    cin>>n>>m;
    int** p = new int*[n];
    for(int i = 0; i<n; i++)
    {
        p[i] = new int[m];
        for(int j = 0; j<m ;j++)
        {
            cin>>p[i][j];
        }
    }

    for(int i = 0; i<m; i++)
    {
        delete [] p[i];
    }
    delete []p;
    return 0;
}
