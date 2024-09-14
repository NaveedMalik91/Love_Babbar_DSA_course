#include <bits/stdc++.h>
using namespace std;

int counter(string &str)
{
    int count = 0;
    for (auto ch : str)
    {
        if (ch == '1')
        {
            count++;
        }
    }
    return count;
}
int numberOfBeams(vector<string> &bank)
{
    vector<int> devices;
    for (auto row : bank)
    {
        devices.push_back(counter(row)); // calculates devices in each row
    }
    int beams = 0;
    for (int i = 0; i < devices.size();
         i++) // traverse over the counter vector containing numof devices
              // in each row
    {
        int j = i + 1;
        while (j < devices.size())
        {
            beams += devices[i] * devices[j];
            if (devices[j] == 0)
            {
                j++;
            }
            else
            {
                break;
            }
        }
    }
    return beams;
}
int main(int argc, char const *argv[])
{
    vector<string> str = {"011001","000000","010100","001000"};
    int res = numberOfBeams(str);
    cout<<"The total laser beams = "<<res;
    return 0;
}
