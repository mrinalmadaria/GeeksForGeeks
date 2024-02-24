#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &price)
    {
        // Write your code here..
        int n = price.size();
        vector<int> profit(n, 0);
        int maxprofit = price[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            maxprofit = max(maxprofit, price[i]);
            profit[i] = max(profit[i + 1], maxprofit - price[i]);
        }
        int minprice = price[0];
        for (int i = 1; i < n; i++)
        {
            minprice = min(minprice, price[i]);
            profit[i] = max(profit[i - 1], (price[i] - minprice) + profit[i]);
        }
        return profit[n - 1];
    }
};