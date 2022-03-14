class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int t[rows][cols+2];
    
        //initalization of first col and last col with positive infinty
        
        for(int i = 0 ; i < rows; i++){
            t[i][0] = INT_MAX;
            t[i][cols + 2 -1] = INT_MAX;
        }
        
        // filling first row
        for(int i = 0 ; i < cols ; i++){
            t[0][i+1] = matrix[0][i];
        }
        
        
        // normal looping
        for(int i = 1 ; i < rows ; i++){
            for(int j = 1 ; j < cols + 1 ; j++){
                
                t[i][j] = matrix[i][j-1] +  min( t[i-1][j-1] , min(t[i-1][j], t[i-1][j+1]));
                
            }
        }
        
        
        
        // looping in the last row for ans
        int mini = INT_MAX;
        for(int i = 1 ; i < cols+1 ; i++){
            mini = min(mini, t[rows-1][i]);
        }

        return mini;

        
        
    }
};