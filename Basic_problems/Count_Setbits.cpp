#include<iostream>
using namespace std;
int count_setbits1()
{
    int n;
    cin>>n;
    int count = 0;
    while(n>0)
    {
        int bit = n%2;
        if (bit == 1)
        {
            count++;
        }
        n = n/2;
    }
    return count;
}

int count_setbits2()
{
    int n;
    cin>>n;
    int count = 0;
    while (n>0)
    {
        int bit = (n&1);
        if (bit == 1)
        {
            count++;
        }
        n = n>>1;
    }
    return count;
    
}

int main(int argc, char const *argv[])
{
    int result1 = count_setbits1();
    cout<<"Set bits in number = "<<result1<<endl;
    int result2 = count_setbits2();
    cout<<"Set bits in number = "<<result2;
    return 0;
}
