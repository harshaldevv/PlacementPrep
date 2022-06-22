class Solution {
public:
    bool ispossible(vector<vector<char>> &board, char c, int R, int C){
        
        //check col
        for(int i = 0 ; i < 9 ; i++){
            if(board[i][C] == c){
                return false;
            }
        }
        // check row
        for(int j = 0 ; j < 9 ; j++){
            if(board[R][j] == c){
                return false;
            }
        }
        
        // check the box
        int row = (R/3) *3;
        int col = (C/3) *3;
        
        for(int i = 0 ; i < 3 ; i++ ){
            for(int j = 0 ; j < 3 ;j++){
                if(board[row+i][col+j] == c){
                    return false;
                }
            }
        }
        
        return true;    
    }
    
    bool solve(vector<vector<char>>& board){
        int n = board.size();
        int m = board[0].size();
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] == '.'){
                    // do work now
                    for(char c = '1' ; c <= '9' ; c++){
                        //cout << "i = " << i << " j = " << j << endl;
                        if(ispossible(board, c, i,j)){
                            board[i][j] = c;
                            if(solve(board)){
                                return true;
                            }
                            else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
};