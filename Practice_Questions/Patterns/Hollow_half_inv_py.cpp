#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    for (int rows = 0; rows < 6; rows++)
    {
        for (int col = 0; col < 6; col++ )
        {
            if(rows == 0 || col == 0 || col == 6-rows-1)
            {
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
            
        }
        cout<<endl;
        
        
    }
    
    return 0;
}
