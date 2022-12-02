//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        
        int n = grid.size();
        int m = grid[0].size();
        
        int sx = source.first;
        int sy = source.second;
        
        int tx = destination.first;
        int ty = destination.second;
        
        
        if(sx == tx && sy == ty){
            return 0;
        }
        
        if(grid[sx][sy] == 0){
            return 0;
        }
        
        vector<int> dir{1,0,-1,0,1};
        
        queue<vector<int>> q;
        q.push({sx, sy});
        int steps = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        while(!q.empty()){
            int sz = q.size();
            steps++;
            while(sz--){
                auto front = q.front();
                q.pop();
                
                int currx = front[0];
                int curry = front[1];
                
                if(currx == tx && curry == ty){
                    return steps -1;
                }
                
                for(int k = 0 ; k <4 ; k++){
                    int newx = currx + dir[k];
                    int newy = curry + dir[k+1];
                    
                    if(newx >=0 && newx < n && newy >= 0 && newy < m && !vis[newx][newy] && grid[newx][newy] == 1){
                        vis[newx][newy] = true;
                        q.push({newx, newy});
                    }
                }
            }
        }
        
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends