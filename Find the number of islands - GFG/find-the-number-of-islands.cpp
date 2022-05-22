// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    void dfs(vector<vector<char>> &grid, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != '1'){
            return ;
        }
        
        grid[i][j] = '2'; // island visited
        
        // 
        dfs(grid, i, j+1); //right
        dfs(grid, i, j-1); //left
        dfs(grid,i-1, j); //up
        dfs(grid, i+1, j); // down
        
        // diagonals;
        dfs(grid, i+1, j+1); // down right
        dfs(grid, i-1, j+1); // up right
        dfs(grid, i-1, j-1 ); // up left
        dfs(grid, i+1, j-1); // down left
        
        return ;
        
        
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        int count = 0;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends