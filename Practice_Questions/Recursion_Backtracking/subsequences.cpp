#include <iostream>
#include <vector>
using namespace std;
void print( string input,string output,int index)
{
    if (index >= input.length())
    {   
        cout<<output<<endl;
        return;
    }
    
    //include a char
    char ch = input[index];
    output.push_back(ch);
    print(input,output,index+1);
    //exclude a char or remove the chacter that was included
    output.pop_back();
    print(input,output,index+1);
 
       
}
int main(int argc, char const *argv[])
{
    string str = "abc";
    string empty = "";
    int index = 0;
  
    print(str,empty,index);

    return 0;
}
