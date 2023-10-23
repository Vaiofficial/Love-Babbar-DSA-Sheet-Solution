#include <bits/stdc++.h>
using namespace std;

void buySell(int prices[], int i, int &minPrice, int &maxProfit, int Listsize)
{
    // base case
    if (i == Listsize)
    {
        return;
    }

    if (prices[i] < minPrice)
        minPrice = prices[i];
    int currentProfit = prices[i] - minPrice;
    if (currentProfit > maxProfit)
        maxProfit = currentProfit;

    // recursive call
    buySell(prices, i + 1, minPrice, maxProfit, Listsize);
}

int main()
{
    int prices[] = {2, 5, 6, 34, 77};
    int size = 5;
    int minPrice = INT_MAX;
    int maxProfit = INT_MIN;

    buySell(prices, 0, minPrice, maxProfit, size);

    cout << "The maximum profit we get by selling the stock is :-" << maxProfit << endl;

    return 0;
}