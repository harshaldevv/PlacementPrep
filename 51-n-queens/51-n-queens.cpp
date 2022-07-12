class Solution {
public:
    bool isPossible(vector<string> &board, int currRow, int currCol, int n){
        // go full left
        
        int j = currCol ;
        while(j>=0){
            if(board[currRow][j] == 'Q' ){
                return false;
            }
            j--;
        }
        
        
        // go diagonally up ( i--, j--)
        int i = currRow;
        j = currCol;
        
        while(i >=0  && j >=0 ){
            if(board[i][j] == 'Q'){
                return false;
            }
            i--;
            j--;
        }
        
        
        // go diagonally down ( i++, j--)
        i = currRow;
        j = currCol;
        
        while(i < n && j >=0){
            if(board[i][j] == 'Q'){
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
    void solve(vector<string>&board, int currCol, vector<vector<string>>&ans, int n){
       
        // n = board's size --> n*n = totalrows * totalcolumns
        if(currCol >= board.size()){
            ans.push_back(board);
            return ;
        }
        
        for(int i = 0 ; i < n ; i++){
            if(isPossible(board, i, currCol, n)){
                board[i][currCol] = 'Q';
                solve(board, currCol+1, ans, n);
                board[i][currCol] = '.';
            }
        }
        
        return ;
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        
        string s = "";
        
        for(int i = 0 ; i < n ; i++){
            s+='.';
        }
        
        vector<string> board(n,s);
        
        solve(board, 0, ans, n);
        
        return ans;
        
        // basically har col pe toh jana hai
        
        
        
    }
};