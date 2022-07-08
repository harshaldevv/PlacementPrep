class Solution {
public:
    int t[100+1][100+1];
    
    int helper(int i, int j){
        if(i < 0 || j < 0){
            return 0;
        }
        
        if(i == 0 && j == 0){
            return 1;
        }
        
        return helper(i-1, j) +  helper(i, j-1);
    }
    
    int helperWithMemo(int i, int j){
        if( i < 0 || j <  0){
            return 0;
        }
        if(i == 0 && j == 0){
            return 1;
        }
        if(t[i][j] != -1){
            return t[i][j];
        }
        
        t[i][j] = helperWithMemo(i-1,j) + helperWithMemo(i, j-1);
        return t[i][j];
        
        
        
    }
    int uniquePaths(int m, int n) {
        
        // return helper(m-1, n-1);
        
        memset(t, -1, sizeof(t));
        return helperWithMemo(m-1, n-1);
        
    }
};