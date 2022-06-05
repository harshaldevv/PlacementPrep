class Solution {
public:
    //int ans = 0;
    bool possible(int r, int c, int n, vector<string> &board){
        
        int tempR;
        int tempC;
        
        //check left;
        for(int i = c ; i>=0 ; i--){
            if(board[r][i] == 'Q'){
                return false;
            }
        }
    
        //check upper diagonal left;
        tempR = r;
        tempC = c;
        while(tempR >= 0 && tempC >=0){
            if(board[tempR][tempC] == 'Q'){
                return false;
            }
            tempR--;
            tempC--;
        }
        
        //check lower diagonal left
        tempR = r;
        tempC = c;
        while(tempR < n && tempC >= 0){
            if(board[tempR][tempC] == 'Q'){
                return false;
            }
            tempR++;
            tempC--;
        }
        
        return true;
    }
    void dfs(int n, int currcol, vector<string> &board, vector<vector<string>> &ans){
        if(currcol == n){
            ans.push_back(board);
            return;
        }
        
        for(int currrow = 0; currrow < n ; currrow++){
            if(possible(currrow, currcol, n, board)){
                board[currrow][currcol] = 'Q';
                dfs(n, currcol+1, board, ans);
                board[currrow][currcol] = '.';
            }
        }
        return ;
    }
    int totalNQueens(int n) {
        
        if(n==1){
            return 1;
        }
        
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        
        dfs(n, 0, board, ans);
        
        return ans.size();
        
    }
};