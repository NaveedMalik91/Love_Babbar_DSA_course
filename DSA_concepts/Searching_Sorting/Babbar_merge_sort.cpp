#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int start, int mid, int end) {

    //In this approach we are creating two diff arrays separately but in lakshya bhaiya approach we are creating the single array
    int left[mid - start + 1];
    int right[end - mid];
    int leftsize = mid - start + 1;
    int rightsize = end-mid;

    //copy the original array values to left array
    for (int i = 0; i <leftsize; i++) {
        left[i] = arr[start + i];
    }

    //copy the original array values to right array
    for (int j = 0; j < rightsize; j++) {
        right[j] = arr[mid + 1 + j];
    }
     

    //sorting the array 
    int i = 0, j = 0;
    int k = start; //To get main array start index
    while (i < leftsize && j < rightsize) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
           
        } else {
            arr[k++] = right[j++];
            
        }
       
    }
    //any left array element pending
    while (i < leftsize) {
        arr[k] = left[i];
        i++;
        k++;
    }

    //any right array element pending
    while (j < rightsize) {
        arr[k] = right[j];
        j++;
        k++;
    }
    
}
void merge_Sort(int arr[],int start,int end)
{
    //base case
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
    int arr[7] = {7,6,5,-4,3,2,1};
    int start = 0;
    int end = 6;
    merge_Sort(arr,start,end);
    for (int i = 0; i < 7; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}