// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knap(int wt[], int val[], int n, int W, vector<vector<int>> &t){
       if(n== 0 || W == 0){
           return 0;
       }
       
       if(t[n][W] != -1){
           return t[n][W];
       }
       
       if(wt[n-1] <= W){
           t[n][W] = max(val[n-1] + knap(wt, val, n-1, W-wt[n-1], t), knap(wt, val, n-1, W, t));
           
       }
       else{
           t[n][W] = knap(wt, val, n-1, W, t);
           return t[n][W];
       }
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       
       vector<vector<int>> t(n+1, vector<int>(W+1, -1));
       
       
       
       return knap(wt, val, n, W, t);
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