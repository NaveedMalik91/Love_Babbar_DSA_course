#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
  int n;
  cout << "Enter the number of rows" << endl;
  cin >> n;
  //Inverted half pyramid
  for (int rows = 0; rows < n; rows++)
  {
    for (int col = 0; col < n - rows; col++)
    {
      cout << "*";
    }
  
    //hollow pyramid
    for (int col = 0; col < 2 * rows + 1; col++)
    {
      cout << " ";
    }

  //Inverted half pyramid
    for (int col = 0; col < n-rows; col++)
    {
      cout<<"*";
    }
    cout<<endl;
  }
  // Lower half
  for(int rows = 0;rows<n;rows++)
  {
    for (int col = 0; col < rows+1; col++)
    {
      cout<<"*";
    }
    for (int col = 0; col < 2*n-2*rows-1; col++)
    {
      cout<<" ";
    }
    for (int col = 0; col < rows+1; col++)
    {
      cout<<"*";
    }
    
    cout << endl;
  }

    
  return 0;
}