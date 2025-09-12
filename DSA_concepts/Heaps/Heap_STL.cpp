#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {10, 20, 5, 15, 30};

    // Max-heap
    make_heap(v.begin(), v.end());
    cout << "Max heap:";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    cout << "Max-heap top: " << v.front() << endl; // 30

    v.push_back(25);                                  // Actually Push a new element
    push_heap(v.begin(), v.end());                    // maintains heap structure i.e. replacement part
    cout << "After push, max: " << v.front() << endl; // 30

    pop_heap(v.begin(), v.end()); // mainatains heap structure by just adding the correct element at popped position
    int maxVal = v.back();        // actual max
    v.pop_back();                 // actually pop the element from last
    cout << "Popped max: " << maxVal << endl;



    // Min-heap
    vector<int> vmin = {10, 20, 5, 15, 30};
    make_heap(vmin.begin(), vmin.end(), greater<int>());
    cout << "Min heap:";
    for (int i = 0; i < vmin.size(); i++)
    {
        cout << vmin[i] << " ";
    }
    cout << endl;
    cout << "Min-heap top: " << vmin.front() << endl; // 5



    cout<<is_heap(vmin.begin(),vmin.end());

    
    return 0;
}
