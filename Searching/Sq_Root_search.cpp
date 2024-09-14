#include<iostream>
using namespace std;
double sqrt(int x)
{
    double s = 0; //int
    double e = x; //int
    double ans = -1; //int
    
    while (s<=e)
    {
        double mid = s+(e-s)/2; //long long int mid
        if (mid*mid == x)
        {
            return mid;
        }
        else if (mid*mid < x)
        {
            ans = mid;
            s = mid+0.01; //mid+1
        }
        else
        {
            e = mid-0.01; //mid-1
        }
        
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int x = 68;
    double res = sqrt(x); //int
    cout<<"Square root = "<<res;
    return 0;
}
