#include<iostream>
using namespace std;
bool palindromic(string str, int start, int end)
{
    if (start>=end)
    {
        return false;
    }
    if (start <= end)
    {
        if (str[start] == str[end])
        {
            return true;
        }
        
        
    }
    return palindromic(str,start+1,end-1);
    
    
}
int main(int argc, char const *argv[])
{
    string str = "racecar";
    int start = 0;
    int end = str.size()-1;
    bool res = palindromic(str,start,end);
    if (res == true)
    {
        cout<<"Palindromic string"<<endl;
    }
    else{
        cout<<"Not palindromic"<<endl;
    }
    
    return 0;
}
