#include<iostream>
using namespace std;
void remove_occurences(string& str, string& sub)
{
    int index = str.find(sub); //start index of substring
    if (index == string::npos)
    {
        return;
    }
    if (index != string::npos)
    {
        string left_str = str.substr(0,index);
        string right_str = str.substr(index+sub.size(), str.size());
        str = left_str+right_str;
    }
    return remove_occurences(str,sub);

    
}
int main(int argc, char const *argv[])
{
    string str = "daabcbaabcbc";
    string sub = "abc";
    remove_occurences(str,sub);
    cout<<str;
    return 0;
}
