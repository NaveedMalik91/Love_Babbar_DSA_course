#include<bits/stdc++.h>
using namespace std;
void subseq(string str,string output,int index)
{
    if (index>=str.length())
    {
        cout<<output<<endl;
        return;
    }
    char ch = str[index];
    //exclude
    subseq(str,output,index+1);
    //include
    output.push_back(ch);
    subseq(str,output,index+1);
    
}
int main(int argc, char const *argv[])
{
    string str = "abc";
    string output = "";
    int index = 0;
    subseq(str,output,index);
    return 0;
}
