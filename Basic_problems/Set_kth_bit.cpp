#include<iostream>
using namespace std;
int kth_bit()
{
    int N,K;
    cout<<"Enter the number: ";
    cin>>N;
    cout<<"Enter the bit to set: ";
    cin>>K;
    int mask = 1<<K; //left shift
    return N|mask; //bitwise OR

}
int main(int argc, char const *argv[])
{

    int result = kth_bit();
    cout<<result;
    
    return 0;
}
