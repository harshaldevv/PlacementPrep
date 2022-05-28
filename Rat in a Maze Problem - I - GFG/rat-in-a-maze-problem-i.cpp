// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void dfs(int i, int j ,vector<vector<int>> &m, int n, vector<string> &path, string p, vector<vector<int>> &vis){
        if(i < 0 || j < 0 || i >= n || j >= n || vis[i][j] == 1 ){
            return ;
        }
        
        if(m[i][j] == 0){
            // blocked
            return ;
        }
        
        
        
        if( i == n-1 && j == n-1){
            path.push_back(p);
            return ;
        }
        
        // DLRU
        
        vis[i][j] = 1;
        
        // D = i+1, j
        dfs(i+1, j, m, n, path, p + "D" , vis);
        
        // left
        dfs(i, j-1, m, n, path, p+ "L" , vis);
        
        // right
        dfs(i, j+1, m, n, path, p+ "R" , vis);
        
        // up
        dfs(i-1, j, m, n, path, p+ "U" , vis);
        
        vis[i][j] = 0; // back tracking step
        
        return;
        
        
        
        
    }
    vector<string> findPath(vector<vector<int>> &grid, int n) {
        // Your code goes here
        // vector<string > ans;
        vector<string> path;
        vector<vector<int>> vis(n , vector<int> (n,0));
        
        dfs(0, 0, grid, n, path, "", vis);
        return path;
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