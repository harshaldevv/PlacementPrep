// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    int solve(int arr[], int n , int i , int j){
        if(i>=j){
            return 0;
        }
        
        int mini = INT_MAX;
        for(int k = i ; k <= j-1 ; k++){
            int tempAns = solve(arr,n, i, k) + solve(arr, n, k+1, j) + 
                            arr[i-1]*arr[k]*arr[j];
            
            mini = min(tempAns, mini);
        }
        
        return mini;
    }
    
    int solve2(int arr[], int n, int i , int j, vector<vector<int>> &t){
        
        if(i >= j){
            return 0;
        }
        
        if(t[i][j] != -1){
            return t[i][j];
        }
        
        int mini = INT_MAX;
        
        for(int k = i ; k <= j-1 ;k++){
            int tempAns = solve2(arr, n, i, k, t) + solve2(arr,n,k+1, j, t) 
                            + arr[i-1]*arr[j]*arr[k];
            
            mini = min(tempAns, mini);
        }
        
        t[i][j] = mini;
        return mini;
    }
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        // doing recursion + memoization
        vector<vector<int>> t(N+1, vector<int>(N+1, -1));
        return solve2(arr, N, 1, N-1, t);
        
        // recursive code neeche works till 6/127 cases
        //return solve(arr, N, 1, N-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends