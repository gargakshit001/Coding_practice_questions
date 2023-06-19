#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int maxProfit(int price[], int n)
{
  int profit = 0;
  int netProfit = 0;
  int start = price[0];
  for(int i = 1; i < n; i++)
  {
    if(price[i] > start)
    {
      profit = max(profit, price[i] - start);
    }
    else
    {
      netProfit += profit;
      profit = 0;
      start = price[i];
    }
  }
  netProfit += profit;
  return netProfit;
}

int main()
{
  int price[] = {100, 180, 260, 310, 40, 535, 695};
  int n = sizeof(price) / sizeof(price[0]);

  cout << maxProfit(price, n);

  return 0;
}
