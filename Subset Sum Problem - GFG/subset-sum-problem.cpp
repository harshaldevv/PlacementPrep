// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
    int helper(int wt[], int N, int W, vector<vector<int>>& t){
        // maxSum / maxWeight laake dega
        if(N == 0 || W == 0){
            return 0;
        }
        if(t[N][W] != -1){
            return t[N][W];
        }
        if(wt[N-1] <= W){
            
            t[N][W] = max(wt[N-1] + helper(wt, N-1, W- wt[N-1], t), helper(wt, N-1, W, t));
             
            return t[N][W];
        }
        else{
            t[N][W] = helper(wt, N-1, W, t); 
            return t[N][W];
        }
    }
public:
    bool isSubsetSum(int N, int arr[], int sum){
        // code here 
        if(N == 0 || sum == 0){
            return false;
        }
        
        vector<vector<int> > t(N+1, vector<int>(sum+1, -1));
        int maxS = helper(arr, N, sum, t);
        
        if(maxS == sum){
            return true;
        }
        else{
            return false;
        }
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends