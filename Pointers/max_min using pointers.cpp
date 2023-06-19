#include<iostream>
#include<climits>
using namespace std;

int largest(int* arr, int n)
{
    int max_ele = INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(*(arr + i) > max_ele)
        {
            max_ele = *(arr + i);
        }
    }
    return max_ele;
}

int smallest(int* arr, int n)
{
    int min_ele = INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(*(arr + i) < min_ele)
        {
            min_ele = *(arr + i);
        }
    }
    return min_ele;
}

int main()
{
    int a[]={1,2,3};
    int size = sizeof(a)/sizeof(a[0]);
    cout<<largest(a, size)<<endl;
    cout<<smallest(a, size)<<endl;
    return 0;
}

