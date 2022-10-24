class Solution {
public:
    bool check(int R, int C, vector<string> &board, int n){
        
        
        // going left
        for(int j = C ; j >= 0; j--){
            if(board[R][j] == 'Q'){
                return false;
            }
        }
        
        // going up -left
        
        int i = R;
        int j = C;
        
        while( i >= 0 && j >= 0){
            if (board[i][j] == 'Q'){
                return false;
            }
            i--;
            j--;
        }
        
        
        // going down-left
        
        i = R;
        j = C;
        
        while(i < n && j >= 0){
            if (board[i][j] == 'Q'){
                return false;
            }
            i++;
            j--;
            
        }
        
        return true;
    }
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
        if(col >= n){
            
            ans.push_back(board);
            return ;
        }
        
        
        
        for(int r = 0 ; r < n ; r++){
            if(check(r, col, board, n)){
                // cout << "here" << endl;
                board[r][col] = 'Q';
                solve(col +1, board, ans, n);
                board[r][col] = '.';
            }
        }
        
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        
        string  s = "";
        for(int i =0 ; i < n ; i++){
            s += ".";
        }
        
        vector<string> board(n,s);
        
        solve(0, board, ans, n);
        
        return ans;
        
    }
};