#include<iostream>
using namespace std;

int pairSumToX(int input[], int size, int x){
	int pairs = 0;
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(input[i] + input[j] == x)
            pairs++;
		}
	}
	return pairs;
}

/* OPTIMUM SOLUTION

bool hasArrayTwoCandidates(vector<int>& arr, int x) {
        //int n = arr.size();
        sort(arr.begin(),arr.end());
        int s = 0;
        int l = arr.size()-1;
        while(s<l)
        {
            int sum = arr[s]+arr[l];
            if(arr[s]+arr[l] == x)
            {
                return true;
            }
            else if(arr[s]+arr[l]>x)
            {
                l--;
            }
            else if(arr[s]+arr[l]<x)
            {
                s++;
            }
            
            
        }
        return false;
    }
*/


int tripletSumToX(int input[], int size, int x){
	int triplets = 0;
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			for(int k=0; k<size; k++){
				if(input[i] + input[j] + input[k] == x){
                    triplets++;
                    cout<<input[i]<<input[j]<<input[k]<<endl;
                }
                
			}
		}
	}
	return triplets;
}
int main(int argc, char const *argv[])
{
    int n = 5;
    int arr[n];
    int x,y;
    cout<<"Enter array values: \n";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the sum to check with pairs: ";
    cin>>x;
    cout<<"Enter the sum to check with triplets: ";
    cin>>y;
   int result1 = pairSumToX(arr,n,x);
   int result2 = tripletSumToX(arr,n,y);
   cout<<"The number of pairs with sum "<<x<<"= "<<result1<<endl;
   cout<<"The number of triplets with sum "<<y<<"= "<<result2<<endl;
    return 0;
}

