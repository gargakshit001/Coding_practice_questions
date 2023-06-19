#include<iostream>
using namespace std;

int knapsack(int n, int* value, int* weight, int w)
{
  //Base case
  if(n == 0 || w == 0)
  {
    return 0;
  }

  //Recursive Cals
  if(weight[0] > w)
  {
    return knapsack(n - 1, value + 1, weight + 1, w);
  }
  int x = knapsack(n - 1, value + 1, weight + 1, w - weight[0]) + value[0];
  int y = knapsack(n - 1, value + 1, weight + 1, w);

  return max(x, y);
}

int main()
{
  int n, w;
  cin >> n;

  int* value = new int[n];
  int* weight = new int[n];

  for(int i = 0; i < n; i++)
  {
    cin>>value[i];
  }

  for(int i = 0; i < n; i++)
  {
    cin>>weight[i];
  }

  cin>>w;

  cout<<"Maximum value "<<knapsack(n, value, weight, w);
}
