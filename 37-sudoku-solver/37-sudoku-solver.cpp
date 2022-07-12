class Solution {
public:
    bool ispossible(vector<vector<char>> &board, int currRow, int currCol, char c){
        
        // entire  row me char c nahi hona chahiye except i, j
        for(int col = 0 ; col < 9 ; col++){
            if(board[currRow][col] == c){
                return false;
            }
        }
        
        // entire col me char c nahi hona chahiye except i, j
        
        for(int row = 0 ; row < 9 ; row++){
            if(board[row][currCol] == c){
                return false;
            }
        }
        
        
        // us 3x3 me char c nahi hona chahiye except i, j
        int desiredRow = (currRow/3)*3;
        int desiredCol = (currCol/3)*3;
        
        for(int i = desiredRow ; i < desiredRow +3 ; i++){
            for(int j = desiredCol ; j < desiredCol +3 ; j++ ){
                if(board[i][j] == c){
                    return false;
                }
            }
        }
        
        
        
        return true;
        
    }
    bool solve(vector<vector<char>> &board){
        for(int i = 0 ; i< 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                if(board[i][j] == '.'){
                    for(char c = '1' ; c <= '9' ; c++){
                        if(ispossible(board, i, j, c)){
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
                    // we checked all numbers from 1 to 9, but none of them worked
                    // therefore we are returning false 
                }
            }
        }
        
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        
        solve(board);
        
    }
};