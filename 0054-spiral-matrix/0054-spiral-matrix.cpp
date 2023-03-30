class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int rowStart = 0;
        int rowEnd = m-1;
        int colStart = 0;
        int colEnd = n-1;
        
        vector<int> ans;
        
        while(rowStart <= rowEnd && colStart <= colEnd){
            // go left to right
            for(int i = colStart ; i <= colEnd ; i++){
                ans.push_back(matrix[rowStart][i]);
            }
            rowStart++;
            
            if(rowStart > rowEnd){
                break;
            }
            
            //go up to down
            for(int i = rowStart ; i <= rowEnd ; i++){
                ans.push_back(matrix[i][colEnd]);
            }
            colEnd--;
            
            if(colStart > colEnd){
                break;
            }
            
            // go right to left
            for(int j = colEnd ; j >= colStart ; j-- ){
                ans.push_back(matrix[rowEnd][j]);
            }
            rowEnd--;
            
            //go down to up
            for(int i = rowEnd ; i >= rowStart ; i--){
                ans.push_back(matrix[i][colStart]);
            }
            
            colStart++;
        }
        
        return ans;
        
    }
};