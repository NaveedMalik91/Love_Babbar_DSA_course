#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    for (int rows = 0; rows < n; rows++)
    {
        int start = 1;
        for (int col = 0; col < n-rows-1; col++)
        {
            cout<<" ";
        }
        //first and last row
        for (int col = 0; col < 2*rows+1; col++)
        {
           
            if (rows == 0 || rows == n-1)
            {
                if (col%2 == 0)
                {
                    cout<<start;
                    start++;
                }
                else
                {
                    cout<<" ";
                } 
            }


            //first , last and middle columns
            else
            {
                if (col == 0)
                {
                    cout<<1;
                }
                if (col == 2*rows+1-1)
                {
                    cout<<rows+1;
                }
                else
                {
                    cout<<" ";
                }
                
                
                
            }
            
        }
        
        
        cout<<endl;
        
    }
    
    return 0;
}
