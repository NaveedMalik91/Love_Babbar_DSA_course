#include <bits/stdc++.h>
using namespace std;
int garbageCollection(vector<string> &garbage, vector<int> &travel)
{
    int pick_m = 0;
    int pick_G = 0;
    int pick_p = 0;

    int last_m = 0;
    int last_g = 0;
    int last_p = 0;

    int travel_p = 0;
    int travel_g = 0;
    int travel_m = 0;
    // calculate pick time
    for (int i = 0; i < garbage.size(); i++) // for(auto ch:garbage)
    {
        string curr = garbage[i]; // string curr = ch
        {
            for (int j = 0; j < curr.length(); j++) // for(auto ch : curr)
            {
                char ch = curr[j];
                if (ch == 'P') // if(ch == 'p')
                {
                    pick_p++;
                    last_p = i; // last index where plastic truck goes
                }
                else if (ch == 'M')
                {
                    pick_m++;
                    last_m = i;
                }
                else if (ch == 'G')
                {
                    pick_G++;
                    last_g = i;
                }
            }
        }
    }
    // calculate travel time
    for (int i = 0; i < last_p; i++)
    {
        travel_p += travel[i]; // upto last position add the time to get travel time for plastic truck
    }
    for (int j = 0; j < last_g; j++)
    {
        travel_g += travel[j];
    }
    for (int k = 0; k < last_m; k++)
    {
        travel_m += travel[k];
    }
    int ans;
    ans = (pick_p + travel_p) + (pick_G + travel_g) + (pick_m + travel_m);
    return ans;
}
int main(int argc, char const *argv[])
{
    vector<string> garbage = {"G","P","PG","GG"};
    vector<int> travel = {2,4,3};
    int res = garbageCollection(garbage,travel);
    cout<<"Total time to pick all grabage  = "<<res;    return 0;
}
