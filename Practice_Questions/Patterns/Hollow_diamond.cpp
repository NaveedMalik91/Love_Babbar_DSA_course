#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  int n;
  cout << "Enter the number of rows: ";
  cin >> n;

  // Print the remaining stars using the loop
  for (int rows = 0; rows < n; rows++)
  {
    // Print spaces
    for (int space = 1; space <= n - rows - 1; space++)
    {
      cout << " ";
    }

    // Print stars (first and last)
    for (int cols = 0; cols < 2 * rows + 1; cols++)
    {
      if (cols == 0 || cols == 2 * rows)
      {
        cout << "*";
      }
      else
      {
        cout << " ";
      }
    }
    cout << endl;
  }
  for (int row = 0; row < n; row++)
  {
    for (int col = 0; col < row; col++)
    {
      cout << " ";
    }
    for (int i = 0; i < 2 * n - 2 * row - 1; i++)
    {
      if (i == 0 || i == 2 * n - 2 * row - 2)
      {
        cout << "*";
      }
      else
      {
        cout << " ";
      }
    }
    cout << endl;
  }

  return 0;
}