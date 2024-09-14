#include <iostream>
using namespace std;
void sort(int arr[], int size)
{
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    // int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            count1++;
        }
        else if (arr[i] == 1)
        {
            count2++;
        }
        else
        {
            count3++;
        }
    }
    int i = 0;
    while (count1 > 0)
    {
        arr[i] = 0;
        i++;
        count1--;
    }
    cout<<i;
    
    while (count2 > 0)
    {
        arr[i] = 1;
        i++;
        count2--;
    }
    while (count3 > 0)
    {
        arr[i] = 2;
        i++;
        count3--;
    }
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    


//Another way

    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (arr[i]>arr[j])
            {
                swap(arr[i],arr[j]);
            }
            
        }
        
    }
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main(int argc, char const *argv[])
{
    int n = 6;
    int arr[n] = {2, 2, 0, 1, 0, 1};
    // int n = 6;
    sort(arr, n);
    return 0;
}
