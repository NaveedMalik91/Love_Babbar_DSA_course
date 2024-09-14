#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter total values: ";
    cin >> n;
    int arr[n];
    cout << "Enter values:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int max = INT_MIN;
    for (int curr = 0; curr < n; curr++)
    {
        if (arr[curr] > max)
        {
            max = arr[curr];
        }
    }
    cout<<"Largest: "<<max<<endl;

    int second = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > second && arr[i] < max) //less than max but greater than INT_MIN
        {
            second = arr[i];
        }
        
    }
    cout <<"Second largest: "<<second;
    return 0;
}

