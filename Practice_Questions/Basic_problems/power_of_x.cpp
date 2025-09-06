#include <iostream>
using namespace std;

int power(int x, int n) {
    if (n == 0) return 1; // Any number raised to the power of 0 is 1
    if (x == 0) return 0; // 0 raised to any power is 0, but this is a special case often not needed if n > 0

    int temp = power(x, n / 2);
    if (n % 2 == 0) {
        return temp * temp; // When n is even
    } else {
        return x * temp * temp; // When n is odd
    }
}

int main() {
    int x = 2;
    int n = 4;
    cout << "The power of x is: "<<power(x, n) << endl; // Output should be 16 (2^4)
    return 0;
}
