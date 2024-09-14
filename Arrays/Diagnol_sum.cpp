#include<iostream>
using namespace std;
void SUM(int arr[][3],int rows,int cols)
{
    
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        
        
        for (int j = 0; j < cols; j++)
        {
            if (i == j)
            {
                sum = sum+arr[i][j];
            }
            
            
        }
        
        
        
    }
    cout<<sum<<endl;
    

}
int main(int argc, char const *argv[])
{
    int a,b;
    int arr[][3] = {
                    {1,2,3,},
                    {3,4,5},
                    {5,6,7}
    };
    cin>>a>>b;
    SUM(arr,a,b);
    return 0;
}
