#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, vector<int> &temp, int start, int mid, int end)
{
    int left_index = start;
    int right_index = mid + 1;
    int main_index = start;

    // Agr left aur right bounds me hai toh sort karo
    while (left_index <= mid && right_index <= end)
    {
        // agr left array ka element chota ahai tph use temp me daal do
        if (arr[left_index] <= arr[right_index])
        {

            temp[main_index] = arr[left_index];
            main_index++;
            left_index++;
        }
        // nahi toh right wala temp me daal do
        else
        {

            temp[main_index] = arr[right_index];
            main_index++;
            right_index++;
        }
    }

    // agr left aur right array ka size diff hai toh bache hue elements ko handle karo
    while (left_index <= mid)
    {

        temp[main_index] = arr[left_index];
        main_index++;
        left_index++;
    }

    while (right_index <= end)
    {
        temp[main_index] = arr[right_index];
        main_index++;
        right_index++;
    }

    // The temp array will have the sorted elements but along with this it will
    // also have some empty blocks, so we will take only the elments withing the start-end
    // copy the merge and sorted array into original array
    while (start <= end)
    {
        arr[start] = temp[start];
        start++;
    }
}

void merge_sort(vector<int> &arr, vector<int> &temp, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = start + (end - start) / 2;
    merge_sort(arr, temp, start, mid);
    merge_sort(arr, temp, mid + 1, end);

    // conquer by merging the arrays
    merge(arr, temp, start, mid, end);
}
int main(int argc, char const *argv[])
{
    vector<int> arr = {5, 4, 3, 2, 1};
    vector<int> temp(arr.size(), 0);
    int size = arr.size();
    int start = 0;
    int end = size - 1;
    merge_sort(arr, temp, start, end);
    for (auto i : arr)
    {
        cout << i << " ";
    }

    return 0;
}
