class Solution {
public:
    
    void flipThisRow(vector<vector<int>> &grid, int r){
        int cols = grid[0].size();
        for(int j = 0 ; j < cols; j++ ){
            grid[r][j] = !grid[r][j];
        }
        return;
    }
    
    void flipThisColumn(vector<vector<int>> &grid, int c){
        int rows = grid.size();
        
        for(int i = 0 ; i < rows ; i++){
            grid[i][c] = !grid[i][c];
        }
        
        return ;
    }
    
   
    int matrixScore(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        // greedy solution --> 
        
        // step 1 --> flip all the rows whose first bit is 0
        for(int i = 0 ; i < m ; i++){
            if(grid[i][0] == 0){
                flipThisRow(grid, i);
            }
        }
        
        // printRow(grid[0]);
        
        //step 2 --> start from first column, flip all the bits of this column
        // if the number of 1s is <= row_size/2 --> and row_size = "m"
        for(int j = 1  ; j < n ; j++){
            int ones = 0;
            for(int i = 0 ; i< m ; i++){
                if(grid[i][j] == 1){
                    ones++;
                }
            }
            
            if(ones <= m/2){
                flipThisColumn(grid, j);
            }
        }
        
        // calculate sum
        int sum = 0;
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    sum += (grid[i][j])*(1<<(n-j-1));
                }
            }
            // cout << "sum = " << sum << endl;
        }
        
        return sum;
        
    }
};