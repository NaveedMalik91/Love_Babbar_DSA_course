#include<iostream>
using namespace std;
void moveNegative(int arr[], int n){
    int i=0, j=n-1;
    while(i<j){
        while(arr[i]<0 && i<j){ // shift back to elements untill condition satisfied
            i++;
        }
        while(arr[j]>0 && i<j){ //shift back to elements untill condition satisfied
            j--;
        }
        swap(arr[i], arr[j]); // swap the elements
       // i++;
        //j--;
    }
}
int main(){
    int n = 11;
    int arr[n] = {2, -22, 1, -5, 4,44,-55,-2,11,-56,23};
    moveNegative(arr, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}