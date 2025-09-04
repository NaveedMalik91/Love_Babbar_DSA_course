#include<iostream>
#include<cmath>
using namespace std;
 
int main() {
    int n,sum=0,factor=0;
    cin>>n;
    while(n>0){
        int digit = n%10;
        sum = sum + digit*pow(2,factor++);
        n = n/10;
    }
    cout<<sum;
    return 0;
}