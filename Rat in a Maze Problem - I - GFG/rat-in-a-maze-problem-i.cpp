// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void helper(vector<vector<int>> &grid, string path, int i, int j, int n, vector<vector<bool>> &vis, vector<string> &ans){
        
        if( i < 0 || i >= n || j < 0 || j >= n ){
            return ;
        }
        
        if(grid[i][j] == 0){
            return ;
        }
        
        if(vis[i][j] == true){
            return ;
        }
        
        if( i == n-1 && j == n-1){
            ans.push_back(path);
            return ;
        }
        
        vis[i][j] = true;
        
        helper(grid, path +"U", i-1, j, n, vis, ans);
        helper(grid, path +"D", i+1, j, n, vis, ans);
        helper(grid, path +"L", i, j-1, n, vis, ans);
        helper(grid, path +"R", i, j+1, n, vis, ans);
        
        vis[i][j] = false; // backtrack
        
        return ;
        
    }
    vector<string> findPath(vector<vector<int>> &grid, int n) {
        // Your code goes here
        
        vector<string> ans;
        string path = "";
        
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        
        helper(grid, "", 0,0 ,n, vis, ans);
        
        return ans;
        
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends