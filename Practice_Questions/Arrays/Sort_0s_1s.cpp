#include <iostream>
using namespace std;

//First way
/*void Sort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                
            }
            
            
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout<< arr[i];
    }
}*/


void Sort(int input[], int size){
	int j = 0;
	for(int i=0; i<size; i++){
		if(input[i] == 0){
			int temp = input[j];
			input[j] = input[i];
			input[i] = temp;
            j++;
		}
	}
    for (int i = 0; i < size; i++)
    {
        cout<< input[i];
    }

}
int main(int argc, char const *argv[])
{
    int n;
    int arr[n];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Sort(arr, n);
    return 0;
}
