#include<bits/stdc++.h>
using namespace std;
 int convertmins(string time)
    {
        int ans;
        int hours = stoi(time.substr(0,2));
        int mins = stoi(time.substr(3,2));
        ans = 60*hours+mins;
        return ans;
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> mins;
        for(auto time:timePoints)
        {
            mins.push_back(convertmins(time));
        }
        sort(mins.begin(),mins.end());
        int ans = INT_MAX;
        for(int i = 0;i<mins.size()-1;i++) //iterate upto secons last character so that i+1 takes last position 
        {
            ans = min(ans,mins[i+1]-mins[i]);
        }
        int last = mins.size()-1;
        int last_diff = mins[0]+1440-mins[last];
        ans = min(ans,last_diff);
        return ans;
        
    }
    int main(int argc, char const *argv[])
    {
        vector<string> s {"00:00","23:59","00:00"};
        int ans = findMinDifference(s);
        cout<<"Minimum time difference = "<<ans;
        return 0;
    }
    