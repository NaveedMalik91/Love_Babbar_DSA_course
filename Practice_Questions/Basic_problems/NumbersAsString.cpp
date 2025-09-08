#include <iostream>
#include <vector>
#include<sstream>
#include<algorithm>
using namespace std;
int print( string input)
{
    stringstream ss(input);
    string temp;
    vector<int> v;
    while (getline(ss,temp,','))
    {
        v.push_back(stoi(temp));
    }
    sort(v.begin(),v.end());

    int maxsqsum = v[1]*v[1] + v[2]*v[2];
    int minsqsum = v[0]*v[0] + v[1]*v[1];
    int diff = maxsqsum - minsqsum;
    if (diff < 0)
    {
        return -1;
    }
    
    return diff;
    

       
}
int main(int argc, char const *argv[])
{
   string input = "11,5,7";
   int ans = print(input);
   cout<< ans;
   

    return 0;
}
