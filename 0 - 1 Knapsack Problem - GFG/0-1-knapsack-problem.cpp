// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    int knapSackHelper(int wt[], int val[], int W, int n, vector<vector<int>>& t){
        
        if( n == 0|| W == 0){ //base case
            return 0;
        }
        
        if(t[n][W] !=-1){ // checking if we've already calcuated the desired input
            return t[n][W];
        }
        
        // decision diagram
        
        if(wt[n-1] <= W){
            int op1 = val[n-1] + knapSackHelper(wt, val, W-wt[n-1], n-1, t);
            int op2 = knapSackHelper(wt, val, W, n-1, t);
            t[n][W] = max( op1, op2);
            return t[n][W];
        }
        else{
            t[n][W] = knapSackHelper(wt, val, W, n-1, t);
            return t[n][W];
        }
    }
    
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        // taulation --> bottom down --> SOlution 3
        int t[n+1][W+1];
        
        for(int i = 0 ; i < n+1 ; i++){
            t[i][0] = 0;
        }
        
        for(int j = 0 ; j < W+1 ; j++){
            t[0][j] = 0;
        }
        
        // now doing the work
        // change n --> i, W---> j
        
        for(int i = 1; i < n+1 ; i++){
            for(int j = 1 ; j < W+1 ; j++){
                if(wt[i-1] <= j){
                    t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]] , t[i-1][j]);
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        return t[n][W];
        
        
        
        // // SOlution 2 --> Memoization. --> top down
        // if( n == 0|| W == 0){
        //     return 0;
        // }
        
        // vector<vector<int> > t(n+1, vector<int>(W+1, -1));        
        // int ans = knapSackHelper(wt, val, W, n , t);
        
        // return ans;
        // // solution 2 ends
        
        // Solution 1 --> recursion
    //   // Your code here
    //   if(n == 0 || W == 0){
    //       return 0;
    //   }
       
    //   if(wt[n-1] <= W){
    //       // do the max thingy
    //       return max(val[n-1] + knapSack(W-wt[n-1], wt, val, n-1) , 
    //                             knapSack(W, wt, val, n-1)    );
    //     //   int op1 = val[n-1] + knapSack(W-wt[n-1], wt, val, n-1);
    //     //   int op2 = knapSack(W,wt, val, n-1);
    //     //   return max(op1, op2);
    //   }
    //   else{
    //       return knapSack(W, wt, val, n-1);
    //   }
    }
};

// { Driver Code Starts.

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
}  // } Driver Code Ends