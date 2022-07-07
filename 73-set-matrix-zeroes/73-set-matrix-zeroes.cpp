class Solution {
public:
    
    void fill(vector<vector<int>> &matrix, int row, int col, int m, int n){
        // fill row with -1 . Dont touch those cells that have zero in them
        
        for(int j = 0 ; j < n ; j++){
            if(matrix[row][j] != 0){
                matrix[row][j] = INT_MIN;
            }
        }
        
        // fill col with -1.
        
        for(int i = 0 ; i < m ; i++){
            if(matrix[i][col] != 0){
                matrix[i][col] = INT_MIN;
            }
        }
        
        return ;
    }
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
//         // TC - O(n^3) , SC - O(1)
//         for(int i = 0 ; i < m ; i++){
//             for(int j = 0 ; j < n ; j++){
//                 if(matrix[i][j] == 0){
//                     fill(matrix, i, j, m, n);
//                 }
//             }
//         }
        
        
//         for(int i = 0 ; i < m ; i++){
//             for(int j = 0 ; j < n ; j++){
//                 if(matrix[i][j] == INT_MIN){
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
        
//         return ;
        
        
        bool row = false;
        bool col = false;
        
        for(int i = 0 ; i < m ; i++){
            if(matrix[i][0] == 0){
                col = true;
                break;
            }
        }
        
        for(int j = 0 ; j < n ; j++){
            if(matrix[0][j] == 0){
                row = true;
                break;
            }
        }
        
        
        //traverse the matrix except the first row and column
        for(int i = 1 ; i < m ; i++){
            for(int j = 1 ; j < n ; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        
        for(int i = 1 ; i < m ; i++){
            for(int j = 1 ; j < n ; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(row){
            // fill first row with zero
            for(int j = 0; j < n ; j++){
                matrix[0][j] = 0;
            }
        }
        
        
        if(col){
            for(int i = 0 ; i < m ; i++){
                // fill first col with zero
                matrix[i][0] = 0;
            }
        }
        
        
        return ;
        
        
        
        
    }
};