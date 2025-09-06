#include <iostream>
#include<vector>
using namespace std;
int max_profit_finder(vector<int> &prices, int i, int &min_price, int &max_profit)
{
    if (i == prices.size())
    {
        return 0;
    }
    if (prices[i] < min_price)
    {
        min_price = prices[i];
    }
    int today_profit = prices[i] - min_price;
    if (today_profit > max_profit)
    {
        max_profit = today_profit;
    }
    return max_profit_finder(prices, i + 1, min_price, max_profit);
}
int maxProfit(vector<int> &prices)
{
    int min_price = INT_MAX;
    int max_profit = INT_MIN;
    max_profit_finder(prices, 0, min_price, max_profit);
    return max_profit;
}
int main(int argc, char const *argv[])
{
    vector<int> v{7,1,5,3,6,4};
    int res = maxProfit(v);
    cout<<"Max profit = "<<res;

    return 0;
}
