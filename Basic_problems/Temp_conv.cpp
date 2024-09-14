#include<iostream>
#include<vector>
using namespace std;
int main(int argc, char const *argv[])
{
    vector<int> arr;
    float Celsius;
    cin>>Celsius;
    float Kelvin = Celsius+273.15;
    float Farhenite = Celsius*1.8;
    arr.push_back(Farhenite);
    arr.push_back(Kelvin);
    cout<<"Farenhite = "<<arr.front()<<" and Kelvin ="<<arr.back();
    return 0;
}
