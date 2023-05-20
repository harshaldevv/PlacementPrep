class Solution {
public:
    bool checker(vector<string> board, int row, int col, int &n){
        //going left
        int i = row;
        int j = col;
        
        while(j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        
        j = col;
        
        //going up left
        while(i >= 0 && j >=0){
            if(board[i][j] == 'Q'){
                return false;
            }
            i--;
            j--;
        }
        
        i = row;
        j = col;
        //going down left
        while(i< n && j>=0){
            if(board[i][j] == 'Q'){
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
    bool helper(vector<string> board, int col, int &n, vector<vector<string>> &ans){
        if(col >= n){
            ans.push_back(board);
            return true;
        }
        
        for(int i = 0 ; i < n; i++){
            //check/find a valid posn
            
            if(checker(board, i, col, n)){
                
                board[i][col] = 'Q';
                // queen in valid posn.
                
                bool temp = helper(board, col+1, n, ans);
                
                //backtrack
                board[i][col] = '.';
            }
            
        }
        
        return true;
        
    }
    vector<vector<string>> solveNQueens(int n) {
        
        string s = "";
        for(int i = 0 ; i < n ; i++){
            s+= ".";
        }

        vector<string> board(n, s);
        
        vector<vector<string>> ans;
        
        helper(board, 0, n, ans);
        
        return ans;
        
        
        
    }
};