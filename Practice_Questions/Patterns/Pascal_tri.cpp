#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    for (int rows = 1; rows <= n; rows++)
    {
        int C = 1;
        for (int col = 1; col <= rows; col++)
        {
            cout << C << " ";
            C = C * (rows - col) / col;
        }
        cout << endl;
    }

    return 0;
}
