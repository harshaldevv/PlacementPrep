//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool f(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
        if(j == 0){
            return true;
        }
        
        
        if(i == 0){
           return (arr[0] == j);
        }
        
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        bool notpick = f(i-1, j, arr, dp);
        
        bool take = false;
        
        if(j >= arr[i]){
            take = f(i-1, j- arr[i], arr, dp);
        }
        
        return dp[i][j] = notpick | take;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        
        int n = arr.size();
        
        int k = sum;
        
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        
        return f(n-1, k, arr, dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends