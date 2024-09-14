#include <bits/stdc++.h>
using namespace std;
int min_cost(vector<int> &days, vector<int> &cost, int i)
{if ( i >= days.size())
{
    return 0;
}


    // 1 day pass taken
    int cost1 = cost[0] + min_cost(days, cost, i + 1); // cost = 1+ further pass taken for next days
    // 7 day pass taken
    int passendDay = days[i] + 7 - 1; // from the current day when will my pass get expired
    int curr_day = i;
    while (curr_day< days.size() && days[curr_day] <= passendDay)
    {
        curr_day++; // we can travel upto 7 days further
    }
    //total cost
    int cost2 = cost[1] + min_cost(days, cost, curr_day); // cost = 4+ next days pass if bought

    // 30 day pass taken
    passendDay = days[i] + 30 - 1; // from the current day when will my pass get expired
    curr_day = i;
    while (curr_day< days.size() && days[curr_day] <= passendDay)
    {
        curr_day++; // we can travel upto 30 days further
    }
    //total cost
    int cost3 = cost[2] + min_cost(days, cost, curr_day); // cost = 25+ next days pass if bought
    return min(cost1, min(cost2,cost3));
}
int min_tkt_cost(vector<int> &days, vector<int> &cost)
{
    int i = 0;
    return min_cost(days, cost, i);
}
int main(int argc, char const *argv[])
{
    vector<int> days{2, 5};
    vector<int> cost{1, 4, 25};
    cout <<"The minimum cost = "<< min_tkt_cost(days, cost);
    return 0;
}
