class Solution {
    
    int helper(int currRow, int currCol, vector<vector<int>> &matrix){
        if(currRow == matrix.size()){
            return 0;
        }
        if(currCol == -1 || currCol == matrix[0].size()){
            return 100000; 
            // since max n = 100, and max values of matrix[i][j] = 100
            // therefore 100*100 is the max ans we can get poissible 
            // tehrefore to be safe 10^5 return krwa dia
        }
        
        int ans = INT_MAX;
        
        ans = min(ans, matrix[currRow][currCol] + helper(currRow+1, currCol - 1, matrix));
        ans = min(ans, matrix[currRow][currCol] + helper(currRow+1, currCol , matrix));
        ans = min(ans, matrix[currRow][currCol] + helper(currRow+1, currCol + 1, matrix));
        
        return ans;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        
//         int rows = matrix.size();
//         int cols = matrix[0].size();
    
//         int ans = INT_MAX;
//         for(int i = 0 ; i < cols; i++){
//             ans = min(ans, helper(0, i,matrix));
//         }
        
//         return ans;
        
//         // ^^ recursion gives TLE
        
        
        
        // NEECHE WALA CODE is more explainatory and simple to understand 
        
        
        
        // non recursice aka DP jo kaafi intutitve tha if you could get the feeling of the ques
        // and if you are not stubborn on the question
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