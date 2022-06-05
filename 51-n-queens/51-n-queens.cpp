class Solution {
public:
    
    bool possible(int r, int c, int n , vector<string> &board){
        
        // check left side (column right to left)
        for(int i = c ; i >= 0 ; i--){
            if(board[r][i] == 'Q'){
                return false;
            }    
        }
        
        //check left upper diagonal
        int tempR = r;
        int tempC = c;
        while(tempR>=0 && tempC>=0){
            if(board[tempR][tempC] == 'Q'){
                return false;
            }
            tempR--;
            tempC--;
        }
        
        
        // check left lower diagonal
        tempR = r;
        tempC = c;
        while(tempR<n && tempC>=0){
            if(board[tempR][tempC] == 'Q'){
                return false;
            }
            tempR++;
            tempC--;
        }
        
        return true;

        
        
    }
    
    void recursion(int n, int currCol, vector<vector<string>> &ans, vector<string> &board){
        if(currCol > n){
            return ;
        }
        
        if(currCol == n){
            ans.push_back(board) ;
            return ;
        }
        
        for(int currRow = 0 ; currRow < n ; currRow++){
            // iterating rows
            // cout << "currRow = " << currRow << endl;
            if(possible(currRow, currCol, n, board)){
                board[currRow][currCol] = 'Q';
                recursion(n, currCol +1, ans, board);
                board[currRow][currCol] = '.';
            }
        }
        return ;
    }
    vector<vector<string>> solveNQueens(int n) {
        
        
        vector<vector<string>> ans;
        vector<string> board(n,  string (n, '.') );
        
        // string s(n, '.');
        // for(int i = 0 ; i < n ; i++){
        //     board[i] = s;
        // }
        
        // int col = 0;
        recursion(n, 0, ans, board);
        
        return ans;
        
        
        
    }
};