class Solution {
public:
    bool ispossible(vector<string> &board, int currrow, int currcol, int n){
        // go full left;
        
        int j = currcol;
        while(j>=0){
            if(board[currrow][j] == 'Q'){
                return false;
            }
            j--;
        }
        
        // go diagonal UP (i--, j--)
        int i = currrow;
        j = currcol;
        while(i>=0 && j >=0){
            if(board[i][j] == 'Q'){
                return false;
            }
            i--;
            j--;
        }
        
        // go diagonal Down (i++, j--)
        i = currrow;
        j = currcol;
        while(i < n && j >=0){
            if(board[i][j] == 'Q'){
                return false;
            }
            i++;
            j--;
        }
    
        
        return true;
    }
    
    void helper(vector<string>&board, int currcol, vector<vector<string>>&ans, int n){
        if(currcol >= n){
            ans.push_back(board);
            return ;
        }
        
        for(int i = 0 ; i < n ; i++){
            // iterate through all the rows of currcol and check if a Q can be placed
            if(ispossible(board, i, currcol, n)){
                board[i][currcol] = 'Q';
                helper(board, currcol +1, ans, n);
                board[i][currcol] = '.';
            }
        }
        
        return ;
    }
    int totalNQueens(int n) {
        
        vector<vector<string>> ans;
        
        
        string s = "";
        for(int i = 0 ; i< n ; i++){
            s+='.';
        }
        
        vector<string> board(n, s);
        
        helper(board, 0, ans, n);
        
        return ans.size();
        
    }
};