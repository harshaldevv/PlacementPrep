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
        
        // if(i == 0 && j == 0){ --> this works too but below one is better cuz it help in filling our dp matrix 
        //     return 1;
        // }
        
        if(i == 0 || j == 0){
            return 1; 
            //Starting from cell [m - 1][n - 1] has 2 options: up and left. 
            //If you arrive at m == 0 that means that the only way you can go is left, 
            // that means that you have only 1 option to get there. Similar for n == 0.
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
        
        
        int t[m+1][n+1];
        memset(t, 0, sizeof(t));
        
        //fill first row and first col = 0, except the first cell of the matrix
        // fill first cell of the matrix with 1
        t[0][0] = 1;
        
        for(int i = 1 ; i < m ; i++){
            for(int j = 1 ; j < n ; j++){
                t[i][j] = t[i-1][j] + t[i][j-1];
                cout << t[i][j] << " ";
            }
        }
        
        return t[n-1][m-1];
        
        
        
    }
};