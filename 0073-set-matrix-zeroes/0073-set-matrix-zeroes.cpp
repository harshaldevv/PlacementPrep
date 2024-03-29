class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        bool row = false;
        bool col = false;
        
        for(int j = 0 ; j < n ; j++){
            if(matrix[0][j] == 0){
                col = true;
            }    
        }
        
        for(int i = 0 ; i < m ; i++){
            if(matrix[i][0] == 0){
                row = true;
            }    
        }
        bool zeroFound = false;
        for(int i = 1 ; i < m ; i++){
            for(int j = 1 ; j < n ; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                    // zeroFound = true;
                }
            }
        }
        
        
        for(int i = 1; i < m ; i++){
            for(int j = 1 ; j < n ; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        // cout << "col = " << col << endl;
        // cout << "row = " << row << endl;
        
        if(col){
            for(int j = 0 ; j < n ; j++ ){
                matrix[0][j] = 0;
            }
        }
        
        if(row == true){
            for(int i = 0 ; i < m ; i++ ){
                matrix[i][0] = 0;
            }
        }
        
        return;
        
        
        
        
    }
};