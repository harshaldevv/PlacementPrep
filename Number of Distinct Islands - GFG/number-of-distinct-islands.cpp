//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  vector<int> dir{1,0,-1,0,1};
  bool isvalid(int i, int j, int m, int n){
      return i>=0 && i < m && j >=0 && j < n;
  }
  void dfs(int &i, int &j, vector<vector<int>> &grid, int &orx, int &ory, vector<vector<bool>> &vis, vector<vector<int>> &temp){
      if(vis[i][j] || grid[i][j] != 1){
          return ; //already visited or water(0);
      }
      
      int m = grid.size();
      int n = grid[0].size();
      
      vis[i][j] = true;
      
      temp.push_back({i-orx, j-ory});
      
      for(int k = 0 ; k < 4 ; k++){
          int newx = i + dir[k];
          int newy = j + dir[k+1];
          
          if(isvalid(newx,newy,m,n) && !vis[newx][newy] && grid[i][j] == 1){
              dfs(newx,newy,grid,orx,ory,vis,temp);
          }
      }
      
      return ;
  }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        set<vector<vector<int>>> S;
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] ==1 && !vis[i][j]){
                    
                    vector<vector<int>> temp;
                    
                    dfs(i,j, grid, i,j, vis, temp);
                
                    S.insert(temp);
                }
            }
        }
        
        return S.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends