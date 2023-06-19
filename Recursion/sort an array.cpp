#include<iostream>
using namespace std;

/* iterative sort
void sort_array(int arr[], int n)
{
    for(int i = 0;i<n - 1;i++)
    {
        for(int j = i + 1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
*/

bool rec_sort(int arr[], int n)
{
    if(n==0 || n==1)
    {
        return true;
    }

    if(arr[0]>arr[1])
       {
           return false;
       }
    bool small_output = rec_sort(arr + 1, n - 1);
    return small_output;

}

void print(int arr[], int n)
{
    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i<n; i++)
    {
        cin>>a[i];
    }
    rec_sort(a, n);
    //print(a, n);
    return 0;
}
