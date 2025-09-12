#include <iostream>
using namespace std;

class Heap
{
private:
    int *arr;
    int size;  //will hold the last index of the array
    int max_size;

public:
    Heap(int max_size)
    {
        this->size = 0; // starting me no element
        this->max_size = max_size;
        this->arr = new int[max_size];
    }

    void insert_max_heap(int val)
    {
        if (size == max_size)
        {
            cout << "Heap overflowed can't add more" << endl;
            return;
        }
        // insert at vacant position
        int index = size;
        size++;
        arr[index] = val;

        // move to its correct position
        // untill reach root we will check every parent
        while (index > 0)
        {
            int parent_index = (index - 1) / 2; // going from child to parent
            if (arr[index] > arr[parent_index])
            {
                swap(arr[index], arr[parent_index]);

                // next index to be checked will be the parentindex with whcih swapping is done
                index = parent_index;
            }
            else
            {
                break;
            }
        }
    }

    int delete_heap_node(){
        //get the root/max element
        int del_ele = arr[0];

        //replace the root with the last element
        arr[0] = arr[size-1];

        //remove the last element from its position
        size--;

        int index = 0;

        //comapre each element to bubble down new root to maintain heap structure
        while (index < size) 
        {
            int left_index = 2*index + 1;
            int right_index = 2*index + 2;
            //check left child whether it is greater than new root
            int largest_index = index;
            if (left_index < size && arr[left_index] > arr[largest_index]  )
            {
                largest_index = left_index; 
                
            }
            
            //check right child whether it is greater than new root
            if (right_index < size &&  arr[right_index] > arr[largest_index])
            {
                largest_index = right_index; 
                
            }
            
            // agr no change means current node/new node is already larger than child
            if (index == largest_index)
            {
                break;
            }
            else{
                swap(arr[index],arr[largest_index]);
                index = largest_index ; // it will store next index to be checked 
            }
            

        }
        return del_ele;
        



    }

    void print_heap()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
    Heap h(20);
    h.insert_max_heap(10);
    h.insert_max_heap(20);
    h.insert_max_heap(40);
    h.insert_max_heap(90);
    h.insert_max_heap(60);
    h.insert_max_heap(30);

    h.print_heap();

    cout<<"Deleted element = "<<h.delete_heap_node()<<endl;
    cout<<"Deleted element = "<<h.delete_heap_node()<<endl;
    cout<<"Deleted element = "<<h.delete_heap_node()<<endl;
    cout<<"Deleted element = "<<h.delete_heap_node()<<endl;
    cout<<"Deleted element = "<<h.delete_heap_node()<<endl;
    cout<<"Deleted element = "<<h.delete_heap_node()<<endl;

   

    return 0;
}
