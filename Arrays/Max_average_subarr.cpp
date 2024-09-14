#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Brute force
double Max_avg(vector<int> &v, int &k)
{
    int i = 0;
    int j = k - 1;
    double max_sum = INT_MIN;
    while (j < v.size())
    {
        double sum = 0;
        for (int start = i; start <= j; start++)
        {
            sum = sum + v[start];
        }
        max_sum = max(max_sum, sum);
        i++;
        j++;
    }
    double result = max_sum / k;
    return result;
}

// Optimum Solution
double MAX_AVG(vector<int> &v, int &k)
{
    int i = 0;
    int j = k - 1;
    int sum = 0;
    for (int x = i; x <= j; x++)
    {
        sum = sum+v[x];
    }
    int max_sum = sum;
    j++; //to check wheter next window exist after first subarray. e.g incase of k=4 and also total arrray values =4;
    while (j < v.size())
    {
       sum = sum-v[i++];
       sum = sum + v[j++];
       max_sum = max(max_sum,sum);
    }
    double result = double(max_sum) / k;
    return result;
}
int main()
{
    vector<int> v = {1, 12, -5, -6, 50, 3};
    int k = 4;
    double result1 = Max_avg(v, k);
    cout << result1<<endl;
    double result2 = MAX_AVG(v, k);
    cout << result2;
    return 0;
}