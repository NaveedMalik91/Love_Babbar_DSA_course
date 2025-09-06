#include<bits/stdc++.h>
using namespace std;
void string_permutations(string &str, int index)
{
    if(index >= str.length())
    {
        cout<<str<<" ";
        return;
    }
    for (int i = index; i < str.length(); i++)
    {
        swap(str[index],str[i]);
        string_permutations(str,index+1);
        //Backtracking:-  during travelling back from recursive call
        //some additional statements need to be executed to nullify the previous results
        //by passing the string by reference the changes will occur each time changes made so
        // in order to nullify we are swapping again here.
        swap(str[index],str[i]);
    }
    
    
}
int main()
{
    int index = 0;
    string str = "abc";
    string_permutations(str,index);
    return 0;
}
