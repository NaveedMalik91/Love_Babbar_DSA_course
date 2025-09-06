#include<iostream>
using namespace std;
void reverse_str(string &str,int start, int end)
{
    if(start>=end)
    {
        return;
    }
    if (start < end)
    {
        swap(str[start],str[end]);
    }
    return reverse_str(str,start+1,end-1);
    
}
int main(int argc, char const *argv[])
{
    string str = "abcdef";
    cout<<"Before: "<<str<<endl;
    int start = 0;
    int end = str.size()-1;
    reverse_str(str,start,end);
    cout<<"After :"<<str;
    return 0;
}
