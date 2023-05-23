//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int f(int i, int j, int wt[], int val[], int n, vector<vector<int>> &dp){
        if(j == 0){
            return 0;
        }
        
        if(i == 0){
            if(j >= wt[i]){
                return val[i];
            }
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int notTake = f(i-1, j, wt, val, n, dp) + 0;
        
        int take = 0;
        
        if( j >= wt[i]){
            take = f(i-1, j - wt[i], wt, val, n, dp ) + val[i];
        }
        
        return dp[i][j] =  max(take, notTake);
    }
    int knapSack(int W, int wt[], int val[], int n) { 
        vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
        return f(n-1, W, wt, val, n, dp);
    //   // Your code here
    //   int t[n+1][W+1];
       
       
    //   for(int i = 0 ; i < n+1; i++){
    //       for(int j = 0 ;  j < W+1 ; j++){
    //           if(i == 0 || j == 0){
    //               t[i][j] = 0;
    //           }
    //       }
    //   }
       
    //   for(int i = 1 ; i < n+1 ; i++){
    //       for(int j = 1; j < W+1 ; j++){
    //           if(wt[i-1] <= j){
    //               t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], t[i-1][j]);
    //           }
    //           else{
    //               t[i][j] = t[i-1][j];
    //           }
    //       }
    //   }
       
    //   return t[n][W];
    }
    
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends