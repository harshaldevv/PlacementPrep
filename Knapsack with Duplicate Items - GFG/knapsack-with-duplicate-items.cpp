// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int f(int i, int j, int wt[], int val[], vector<vector<int>> &dp){
        if(j == 0){
            return 0;
        }
        
        if(i == 0){
            if(j/wt[i] > 0){
                return  (j/wt[i])*val[i];
            }
            else{
                return 0;
            }
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int nottake = f(i-1, j, wt, val, dp);
        
        int take = INT_MIN;
        
        if( j >= wt[i]){
            take = f(i, j- wt[i], wt, val, dp) + val[i];
        }
        
        return dp[i][j] = max(take, nottake);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N, vector<int>(W+1, -1));
        return f(N-1, W, wt, val, dp);
        
        //unbounded knapsack
        // int n = N;
        // int t[n+1][W+1];
        
        // for(int i= 0 ; i < n+1 ; i++){
        //     t[i][0] = 0;
        // }
        
        // for(int j = 0 ; j < W+1; j++){
        //     t[0][j] = 0;
        // }
        
        // for(int i =1 ; i < n+1 ; i++){
        //     for(int j = 1 ; j < W+1 ; j++){
        //         if(wt[i-1] <= j){
        //             t[i][j] = max(val[i-1] + t[i][j-wt[i-1]], t[i-1][j]);
        //         }
        //         else{
        //             t[i][j] = t[i-1][j];
        //         }
        //     }
        // }
        
        // return t[n][W];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends