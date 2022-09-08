class Solution {
public:
    
    bool ispossible(int R, int C, vector<string> &board, vector<vector<string>> &ans, int n){
        // go left
        
        for(int i = C ; i >= 0 ; i--){
            if(board[R][i] == 'Q'){
                return false;
            }
        }
        
        // go diagnoally left up
        int i = R;
        int j = C;
        
        while( i>= 0 && j >=0 ){
            if(board[i][j] == 'Q'){
                return false;
            }
            i--;
            j--;
        }
        
        // go diagnoally left bottom
        i = R;
        j = C;
        
        while(i < n && j >= 0){
            if(board[i][j] == 'Q'){
                return false;
            }
            i++;
            j--;
        }
        
        return true;
        
    }
    
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
        if(col == n){
            ans.push_back(board);
            return ;
        }
        
        int rows = n;
        
        for(int r = 0 ; r < rows ; r++){
            if(ispossible(r, col, board, ans, n)){
                board[r][col] = 'Q';
                solve(col+1, board, ans, n);
                board[r][col] = '.';
            }
        }
        
        return ;
        
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
    
        string s = "";
        
        for(int i = 0 ; i < n ; i++){
            s+= '.';
        }
        
        vector<string> board(n, s);
        
        // check every column
        solve(0, board, ans, n);
        
        return ans;
        
    }
};