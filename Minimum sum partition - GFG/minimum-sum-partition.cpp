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
	    
	    bool t[n+1][sum+1];
	    
	    for(int i = 0 ; i < n+1 ; i++){
	        t[i][0] = true;
	    }
	    for(int j = 0 ; j < sum+1; j++){
	        t[0][j] = false;
	    }
	    
	    t[0][0] = true;
	    
	    for(int i = 1 ; i < n+1 ; i++){
	        for(int j = 1 ; j < sum +1 ; j++){
	            if(arr[i-1] <= j){
                    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
	            }
	            else{
	                t[i][j] = t[i-1][j];
	            }
	        }
	    }
	    
	    //get the last row of the matrix;
	    
	    vector<int> v;
	    
	    for(int j = 0 ; j< sum+1 ; j++){
	        if(t[n][j] == true){
	            v.push_back(j);
	        }
	    }
	    
	    return abs(sum - 2*v[v.size()/2]);
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