class Solution {
public:
    int t[100 +1][100+1];
    int helper(int i, int j , vector<vector<int>> &grid){
        if(i < 0 || j < 0){
            return 0;
        }
        
        if(grid[i][j] == 1){
            // obstacle
            return 0;
        }
        
        if(i == 0 && j == 0){
            return 1;
        }
        
        return helper(i-1, j, grid) + helper(i, j-1, grid);
            
    }
    
    int helperWithMemo(int i, int j, vector<vector<int>> &grid){
        if( i < 0 || j < 0){
            return 0;
        }
        if(grid[i][j] == 1){
            return t[i][j] = 0;
        }
        
        if(i == 0 && j == 0){
            return t[i][j] = 1;
        }
        
        if(t[i][j] != -1){
            return t[i][j];
        }
        
        return t[i][j] = helperWithMemo(i-1, j, grid) + helperWithMemo(i, j-1, grid);
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        
        // return helper(m-1, n-1, grid);  --> recursive approach
        
        
        memset(t, -1, sizeof(t));
        return helperWithMemo(m-1, n-1, grid);
    }
    
    
};