#include<bits/stdc++.h>
using namespace std;
int solve(string &str1, string &str2, int i, int j)
{
    if (i>= str1.size()) //str1 size is less than str2
    {
        return str2.length()-j;
    }
    if (j>= str2.size()) //str2 size is less than str1
    {
        return str1.length()-i;
    }
    int ans = 0;
    if (str1[i] == str2[j])
    {
        ans = 0 + solve(str1,str2,i+1,j+1);
    }

    else{
        //insert
        int option1 = 1+solve(str1,str2,i,j+1);
        //delete
        int option2 = 1+solve(str1,str2,i+1,j);
        //update
        int option3 = 1+solve(str1,str2,i+1,j+1);
        ans = min(option1,min(option2,option3));
    }
    return ans;
    
    
}
int word1Toword2(string str1, string str2)
{
    int i = 0;
    int j = 0;
    int ans = solve(str1,str2,i,j);
    return ans;

}
int main()
{
    string str1 = "horse";
    string str2 = "ros";
    int ans = word1Toword2(str1,str2);
    cout<<"minimum number of steps = "<<ans;
    return 0;
}