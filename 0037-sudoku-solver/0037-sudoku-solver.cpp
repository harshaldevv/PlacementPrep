class Solution {
public:
    bool isvalid(vector<vector<char>> &board, int r , int c, char numb){
        
        
        int ROW = r/3;
        int COL = c/3;
        
        // grid check (third condition)
        for(int  i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                int tx = 3*ROW + i;
                int ty = 3*COL + j;
                
                if(board[tx][ty] == numb){
                    return false;
                }
            }
        }
        
        // row check
        
        for(int j = 0 ; j < 9 ; j++){
            if(board[r][j] == numb){
                return false;
            }
        }
        
        // col check
        
        for(int i = 0 ; i < 9 ; i++){
            if(board[i][c] == numb){
                return false;
            }
        }
        
        
        
        return true;
    }
    
    bool solve (vector<vector<char>> &board){
        
        
        for(int i =0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                if(board[i][j] == '.'){
                    for(char x = '1' ; x <= '9' ;x++){
                        if(isvalid(board, i, j, x)){
                            // cout << "x = " << x << endl;
                            board[i][j] = x;
                            
                            bool completed = solve(board);
                            
                            if(completed){
                                return true;
                            }
                            board[i][j] = '.';
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
        
        return ;
        
    }
};