#include<iostream>
#include<climits>
using namespace std;

/*ITERATIVE METHOD
int kmin(int a[], int n, int k)
{
    int min_ele=INT_MAX;
    for(int i=0;i<k;i++)
    {
        min_ele=INT_MAX;
        for(int j=0;j<n;j++)
        {
            if(a[j]<min_ele)
            {
                min_ele=a[j];
            }
        }
        for(int l=0;l<n;l++)
        {
            if(a[l]==min_ele)
            {
                if(i!=k-1)
                {
                    a[l]=INT_MAX;
                }
            }
        }
    }
    return min_ele;
}

int kmax(int a[], int n, int k)
{
    int max_ele=INT_MIN;
    for(int q=0;q<k;q++)
    {
        max_ele=INT_MIN;
        for(int w=0;w<n;w++)
        {
            if(max_ele<a[w])
            {
                max_ele=a[w];
            }
        }
        for(int e=0;e<n;e++)
        {
            if(a[e]==max_ele)
            {
                if(q!=k-1)
                {
                    a[e]=INT_MIN;
                }
            }
        }
    }

    return max_ele;
}*/

//USING RECURSION
int kmin_rec(int a[], int n, int k)
{
    int min_ele = INT_MAX, loop=0;
    if(k==1)
    {
        min_ele=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(a[i]<min_ele)
            {
                min_ele=a[i];
            }
        }
        loop++;
        /*for(int i=0;i<n;i++)
        {
            if(a[i]=min_ele)
            {
                if(loop!=k)
                {
                    a[i]=INT_MAX;
                }
            }
        }
    int ans = kmin_rec(a, n, k-1);
    return ans;*/
        return min_ele;
    }
    int ans = kmin_rec(a, n, k-1);
    return ans;
    for(int i=0;i<n;i++)
    {
        if(a[i]=min_ele)
        {
            if(loop!=k)
            {
                a[i]=INT_MAX;
            }
        }
    }
   // int ans = kmin_rec(a, n, k-1);
  //  return ans;

}

void print(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    cout<<"enter array size "<<endl;
    int n;
    cin>>n;
    cout<<"enter array elements "<<endl;
    int arr1[n];
    int arr2[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    for(int i=0;i<n;i++)
    {
        arr2[i]=arr1[i];
    }
    print(arr1, n);
    cout<<"enter key: "<<endl;
    int k;
    cin>>k;
    cout<<"kth smallest element: "<<kmin(arr1, n, k)<<endl;
    cout<<"kth max element is: "<<kmax(arr2, n, k)<<endl;

    return 0;
}
