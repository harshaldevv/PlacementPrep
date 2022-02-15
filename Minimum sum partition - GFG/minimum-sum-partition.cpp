// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    if(n==0){
	        return 0;
	    }
	    
	    int sum = 0;  //maxRange of S1
	    
	    for(int i = 0 ; i < n ; i++){
	        sum+=arr[i];
	    }
// 	    5
// 20 19 18 20 16

	    int rows = n+1;
	    int cols = floor(sum/2) +1;
	    bool t[rows][cols];
	    
	    // initlaization
	    
	    for(int i = 0 ; i < rows; i++){
	        t[i][0] = true; 
	    }
	    
	    for(int j = 0 ;  j < cols ; j++){
	        t[0][j] = false;
	    }
	    
	    t[0][0] = true;
	    
	    for(int i = 1 ; i < rows ; i++){
	        for(int j = 1 ; j< cols ; j++){
	            if(arr[i-1] <= j){
	                // include/ exclude
	                t[i][j] = t[i-1][j] || t[i-1][j- arr[i-1]];
	            }
	            else{
	                t[i][j] = t[i-1][j];
	            }
	        }
	    }
	    
	    // get the last row of the matrix
	    
	   // cout << "cols = " << cols << endl;
	    
	    for(int i = cols -1; i>=0 ; i--){
	        if(t[n][i] == true){
	           // cout << t[n][i] << " ";
	            return abs(sum - 2*i); //t[n][i];
	           // return max(t[n][i], t[n][i-1]);
	        }
	    }
	    
	    return 69;
	    
	    
	    
	    
	    
	    
	    
	    
	    
	   // bool t[n+1][sum+1];
	    
	   // for(int i = 0 ; i < n+1 ; i++){
	   //     t[i][0] = true;
	   // }
	   // for(int j = 0 ; j < sum+1; j++){
	   //     t[0][j] = false;
	   // }
	    
	   // t[0][0] = true;
	    
	   // for(int i = 1 ; i < n+1 ; i++){
	   //     for(int j = 1 ; j < sum +1 ; j++){
	   //         if(arr[i-1] <= j){
    //                 t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
	   //         }
	   //         else{
	   //             t[i][j] = t[i-1][j];
	   //         }
	   //     }
	   // }
	    
	   // //get the last row of the matrix with cells that have true
	   // vector<int> v;
	    
	   // for(int j = 0 ; j< sum+1 ; j++){
	   //     if(t[n][j] == true){
	   //         v.push_back(j);
	   //     }
	   // }
	    
	   // return abs(sum - 2*v[v.size()/2]);
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends