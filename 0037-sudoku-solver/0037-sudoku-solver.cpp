class Solution {
public:
    bool rowCheck(char &c, vector<vector<char>> &board, int &row, int &col){

        for(int j = 0 ; j < 9 ; j++){
            if(board[row][j] == c){
                // found
                return true;
            }
        }

        return false;

    }
    
    bool colCheck(char &c, vector<vector<char>> &board, int &row, int &col){

        for(int i = 0 ; i < 9 ; i++){
            if(board[i][col] == c){
                // found
                return true;
            }
        }

        return false;

    }
    
    bool subBoxCheck(char &c, vector<vector<char>> &board, int &row, int &col){

        int x = (row/3)*3;
        int y = (col/3)*3;

        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0; j < 3 ; j++){
                int newX = x+i;
                int newY = y+j;

                if(board[newX][newY] == c){
                    // found
                    return true;
                }
            }
        }

        return false;
    }

    bool isAllowed(char &c, vector<vector<char>> &board, int &row, int &col){

        // check function to allow char c at i,j position on the board

        bool isFoundInRow    =   rowCheck(c, board, row, col);
        bool isFoundInCol    =   colCheck(c, board, row, col);
        bool isFoundInSubBox =   subBoxCheck(c, board, row, col);

        return !isFoundInRow && !isFoundInCol && !isFoundInSubBox;

    }

    bool solve(vector<vector<char>>& board){
        int m = board.size();     // 9
        int n = board[0].size();  // 9

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n; j++){
                if(board[i][j] == '.'){
                    // empty found
                    for(char c = '1' ; c <= '9' ; c++){
                        if(isAllowed(c, board, i, j)){
                            board[i][j] = c;
                            // recurse
                            if(solve(board)){
                                return true;
                            }
                            //back track
                            board[i][j] = '.';
                        }
                    }
                    // empty found but no number was possible
                    // so return false; -> as not able to solve this sudoku
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