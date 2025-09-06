#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the number of rows: "<<endl;
    cin>>n;
    
    for (int rows = 0; rows < n; rows++)
    {
        
        for (int cols = 0; cols < n-rows ; cols++) 
        {
            
            cout<<" ";
            
        }
        int counter = 0;
        for (int cols = 0; cols < 2*rows+1; cols++)
        {
           
            if (cols > rows)
            {
                counter--;
                cout<<counter;;
            }
            else{
                counter++;
                cout<<counter;
                
            }
            
        }
        
        cout<<endl;
    }
    
   
    return 0;
}

