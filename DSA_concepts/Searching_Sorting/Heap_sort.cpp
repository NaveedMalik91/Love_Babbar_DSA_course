#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &arr, int size, int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;
    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != index)
    {
        swap(arr[index], arr[largest]);
        heapify(arr, size, largest);
    }
}

void buildMaxHeap(vector<int> &arr)
{
    int size = arr.size();

    //start from leaf nodes i.e. they will present at index i = n/2-1
    //for each node from leaft backwards call heapify function
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
    }
}

void Heap_sort(vector<int> &arr)
{
    buildMaxHeap(arr);
    int size = arr.size();
   while (size!=1)
    {
        swap(arr[0], arr[size-1]);
        size--;
        heapify(arr, size, 0);
    }
}

int main()
{
    vector<int> arr = {10, 20, 2, 14, 4, 7, 21, 9, 6};

    cout << "Original array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    buildMaxHeap(arr);

    cout << "Max Heap: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    Heap_sort(arr);

    cout << "Sorted array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
