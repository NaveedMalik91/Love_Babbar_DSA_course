#include <iostream>
#include <cmath>
using namespace std;
int Number(int num)
{
    int digit; // individual digit
    cout << "Enter digits: " << endl;
    int sum = 0;
    for (int i = 0; i < num; i++)
    {
        cin >> digit;
        sum = sum + digit * (pow(10, num - i - 1));
    }
    return sum;
}
int main()
{
    int num; // number of digits
    cin >> num;
    int result = Number(num);
    cout << result;
    return 0;
}
