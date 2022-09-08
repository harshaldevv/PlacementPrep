class Solution {
public:
    
    bool ispossible(vector<vector<char>> &board, int currrow, int currcol, char k){
        // check this whole row
        for(int i = 0 ; i < 9 ; i++){
            if(board[currrow][i] == k){
                return false;
            }
        }
        
        // check this whole col
        for(int i = 0 ; i < 9  ; i++){
            if(board[i][currcol] == k){
                return false;
            }
        }
        
        // check in the 3x3 box
        
        int x = 3 * (currrow/3);
        int y = 3 * (currcol/3);
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                if(board[ x + i ][ y + j ] == k){
                    return false;
                }
            }
        }
        
        return true;
        
        
    }
    bool solve(vector<vector<char>> &board, int n){
        
        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                
                // cout << i << " , " << j << endl;
                
                if(board[i][j] == '.'){
                    
                    for(char k = '1' ; k <= '9' ; k++ ){
                        
                        if(ispossible(board, i, j, k)){
                            board[i][j] = k;
                            
                            if(solve(board, n)){
                                return true;
                                // dont backtrack now , cuz the ques asked for "one" 
                                // valid sudoku 
                                // had the ques asked for all possible sudokus then we
                                // hum ye solve() wale ke baad backtrack pe bhi jate
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
        int n = board.size();
        
        solve(board, n);
        
        return ;
        
    }
};