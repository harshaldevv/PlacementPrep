class Solution {
public:
    int dfs2(vector<vector<int>> &grid, int i, int j){
        // though this approach is rather non intutive ish
        // the flood fill one is more intutive 
        
        // this uses the leetcode #1254 and 
        // python code in this post's comment -->
        // https://leetcode.com/problems/number-of-enclaves/discuss/266168/Easy-Java-DFS-6ms-solution
        if( i <0 || j < 0 || i>= grid.size() || j >= grid[0].size() ){
            return -1;
        }
        
        if(grid[i][j] != 1){
            return 0;
        }
        
        grid[i][j] = 2;
        
        int a = dfs2(grid, i+1, j);
        int b = dfs2(grid, i, j-1);
        int c = dfs2(grid, i-1, j);
        int d = dfs2(grid, i, j+1);
        
        if(a==-1 || b == -1 || c == -1 || d == -1){
            return -1;
        }
        
        return 1 + a+b+c+d;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j< n ; j++){
                if(grid[i][j] == 1){
                    int temp = dfs2(grid, i, j);
                    if(temp > 0 ){
                        res+=temp;
                    }
                }
            }
        }
        return res;
        
    }
};