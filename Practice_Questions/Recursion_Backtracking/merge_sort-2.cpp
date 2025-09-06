#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int start, int mid, int end) {
    int left[mid - start + 1];
    int right[end - mid];
    int leftsize = mid - start + 1;
    int rightsize = end-mid;

    for (int i = 0; i <leftsize; i++) {
        left[i] = arr[start + i];
    }
    for (int j = 0; j < rightsize; j++) {
        right[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0, k = start;
    while (i < leftsize && j < rightsize) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
           
        } else {
            arr[k++] = right[j++];
            
        }
       
    }
    while (i < leftsize) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < rightsize) {
        arr[k] = right[j];
        j++;
        k++;
    }
    
}
void merge_Sort(int arr[],int start,int end)
{
    if (start < end)
    {
       int mid = start+(end-start)/2;
    
        merge_Sort(arr,start,mid);
        merge_Sort(arr,mid+1,end);

        //Conquer by merging sorted arrays
        merge(arr,start,mid,end);
    }
}
int main()
{
    int arr[7] = {7,6,5,4,3,2,1};
    int start = 0;
    int end = 6;
    merge_Sort(arr,start,end);
    for (int i = 0; i < 7; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}