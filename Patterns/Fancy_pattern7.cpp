/*
Pattern for N = 5
1234554321
1234**4321
123****321
12******21
1********1
*/
#include<iostream>
using namespace std;


int main(){
    int n;
    cin>>n;
    int i=0;
    while(i<n){
        int count = n-i;
        int k=1;
        while(k<=count){
            cout<<k;
            k++;
        }
        int stars = 2*i;
        while (stars > 0)
        {
            cout<<"*";
            stars--;
        }
        
        count = n-i;
        while(count>0){
            cout<<count;
            count--;
        }
        cout<<"\n";
        i++;
    }
}
