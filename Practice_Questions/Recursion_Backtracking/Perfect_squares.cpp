#include<bits/stdc++.h>

using namespace std;
int numSqhelper(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    int ans  = INT_MAX;
    int end = sqrt(n);
    int i = 1;
    while (i <= end)
    {
        int squareroot = i*i;
        int numberofperfectSquares = 1+numSqhelper(n-squareroot); //return 0/1 will acumulared to number of perfectsquarenumbers
        if (numberofperfectSquares < ans)
        {
            ans = numberofperfectSquares;
        }
         i++;
        
    }
    return ans;
    
    
    

}
int numsquares(int n)
{
    return numSqhelper(n)-1; // to remove extra call when raches base case;

}
int main(int argc, char const *argv[])
{
    cout<<"The minimum number of perfect squares required to get sum = n is: "<<numsquares(12);
    
    return 0;
}
