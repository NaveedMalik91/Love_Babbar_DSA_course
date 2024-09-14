#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int compress(std::vector<char> &s)
{
    int index = 0;
    int count = 1;
    char p = s[0];
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == p)
        {
            count++;
        }
        else
        {
            s[index++] = p;
            if (count > 1)
            {
                int start = index;
                while (count)
                {
                    s[index++] = (count % 10) + '0';
                    count /= 10;
                }
                reverse(s.begin() + start, s.begin() + index);
            }
            p = s[i];
            count = 1;
        }
    }
    s[index++] = p;
    if (count > 1)
    {
        int start = index;
        while (count)
        {
            s[index++] = (count % 10) + '0';
            count /= 10;
        }
        reverse(s.begin() + start, s.begin() + index);
    }

    return index;
}

int main()
{
    // Example 1
    vector<char> s1 = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int newLength1 = compress(s1);
    cout << "Compressed vector: ";
    for (int i = 0; i < newLength1; ++i)
    {
        cout << s1[i];
    }
    cout << "\nNew length: " << newLength1 << endl;

    // Example 2
    vector<char> s2 = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    int newLength2 = compress(s2);
    cout << "Compressed vector: ";
    for (int i = 0; i < newLength2; ++i)
    {
        cout << s2[i];
    }
    cout << "\nNew length: " << newLength2 << endl;

    // Example 3
    vector<char> s3 = {'a', 'a', 'a', 'a', 'a','a','a','a','a','a'};
    int newLength3 = compress(s3);
    cout << "Compressed vector: ";
    for (int i = 0; i < newLength3; ++i)
    {
        cout << s3[i];
    }
    cout << "\nNew length: " << newLength3 << endl;

    return 0;
}
