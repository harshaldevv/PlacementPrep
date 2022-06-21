class Solution {
public:
    vector<vector<string>> ans;
    bool ispossible(vector<string> &board, int r, int c){
        int n = board.size();
        
        //checking left
        for(int j = c; j >= 0 ; j--){
            //cout << "hee" <<endl;
            if(board[r][j] == 'Q'){
                return false;
            }
        }
        
        //going up diagonal left
        int R = r;
        int C = c;
        while(R>= 0 && C >=0){
            if(board[R][C] == 'Q'){
                return false;
            }
            R--;
            C--;
        }
        
        R = r;
        C = c;
        while(R<n && C >= 0){
            if(board[R][C] == 'Q'){
                return false;
            }
            R++;
            C--;
        }
        
        return true;
        
        
        
    }
    
    void solve(vector<string> &board, int col, int n){
        
        int rows = n;
       
        if(col == n){
            // last column me bhi bhar gya hai
            ans.push_back(board);
            return;
        }
        
        for(int i = 0 ; i < rows ; i++){
            if(ispossible(board, i, col)){
                board[i][col] = 'Q';
                solve(board, col+1, n);
                board[i][col] = '.';
            }
        }
        
        return ;
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        string s = "";
        for(int i = 0 ; i<n ; i++){
            s+=".";
        }
        
        vector<string> board(n, string(n, '.'));
        
        solve(board, 0, n);
        
        return ans;
        
    }
};