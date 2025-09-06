#include<bits/stdc++.h>
using namespace std;
void quick_sort(vector<int> &vec, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int pivot = end;
    int j = start;
    int i = start - 1;
    while (j < pivot)
    {
        if (vec[j] < vec[pivot])
        {
            i++;
            swap(vec[j],vec[i]);
        }
        j++;
        
    }
    i++;
    swap(vec[i],vec[pivot]);
    quick_sort(vec,start,i-1);
    quick_sort(vec,i+1,end);
    
    
}
int main()
{
    vector<int> vec{5,3,7,1,9,3,6};
    int start = 0;
    int end = vec.size()-1;
    cout<<"Before sorting: ";
    for (int i = 0; i < 7; i++)
    {
        cout<<vec[i]<<" ";
    }
    quick_sort(vec,start,end);
    cout<<endl;
    cout<<"After sorting: ";
    for (int i = 0; i < 7; i++)
    {
        cout<<vec[i]<<" ";
    }
    
    return 0;
}