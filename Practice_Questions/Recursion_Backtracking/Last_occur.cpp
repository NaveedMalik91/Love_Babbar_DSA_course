#include<iostream>
using namespace std;
void Last_occur(string s,int i,char &c,int &ans)
{
    if(i>s.size())
    {
        return;
    }

    if (s[i] == c)
    {
        ans = i;
    }
    return Last_occur(s,i+1,c,ans);
    

}
int main(int argc, char const *argv[])
{
    string s = "abcddesd";
    int i  = 0;
    int ans = -1;
    char str = 'd';
    Last_occur(s,i,str,ans);
    cout<<ans;
    return 0;
}
