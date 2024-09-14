#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    for (int rows = 0; rows < n; rows++)
    {
        for (int col = 0; col < 2*rows+1; col++)
        {
            if (col == 0 ||col == 2*rows+1-1)
            {
                cout<<"* ";
            }
            else
            {
                if (col<=rows)
                {
                    cout<<col<<" ";
                }
                else{
                    cout<<2*rows-col<<" ";
                }
                
                
            }
            
        }
        cout<<endl;
    }
     for (int rows = 0; rows < n-1; rows++)
    {
    
        for (int col = 0; col < 2*n-2*rows-3; col++)
        {
            if (col == 0 || col == 2*n-2*rows-3-1)
            {
                cout<<"* ";
            }
            else{
               
                if (col<=rows)
                {
                    cout<<col<<" ";
                    
                }
                else{
                   cout << 2*(n-2-rows) - col << " ";
                }
                
              }
            
        }
        cout<<endl;
    }
   
    
    return 0;
}
