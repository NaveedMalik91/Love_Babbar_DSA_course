#include <iostream>
using namespace std;

int main() {
  // heart star pattern
  int size;
  cout<<"Enter the number of rows: ";
  cin>>size;

  for (int i = size/2; i < size; i+=2) {
    // print first spaces
    for (int j = 1; j < size - i; j+=2) {
      cout << " ";
    }
    // print first stars
    for (int j = 0; j < i ; j++) {
      cout << "*";
    }
    // print second spaces
    for (int j = 0; j < size - i; j++) {
      cout << " ";
    }
    // print second stars
    for (int j = 0; j < i ; j++) {
      cout << "*";
    }
    for (int j = 1; j < size - i; j+=2) {
      cout << " ";
    }
    cout << "\n";
  }

  //lower inverted pyramid
   for (int i = size; i > 0; i--) {
    for (int j = 0; j < size - i; j++) {
      cout << " ";
    }
    for (int j = 1; j < i * 2; j++) {
      cout << "*";
    }
    cout << "\n";
  }




  return 0;
}