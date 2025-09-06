#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
   
    for (int i = 0; i < 6; i++)
    {
        int k = 0;
        for (int j  = 0; j < 11 ; j++)
        {
            if (j < 5-i)
            {
                cout<<" ";
            }

            else if(k < 2*i+1)
            {
                if (k == 0 || k == 2 * i || i == 5)
                {
                     cout<<"*";
                }
                else{
                    cout<<" ";
                }
                k++;
            }
            cout<<" ";
            
     
        }
        cout<<endl;
        
    }

    return 0;
}