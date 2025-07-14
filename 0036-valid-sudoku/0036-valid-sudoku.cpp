class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int m = board.size();     // 9
        int n = board[0].size();  // 9

        vector<vector<bool>> rowSeen(m, vector<bool>(n, false));
        vector<vector<bool>> colSeen(m, vector<bool>(n, false));
        vector<vector<bool>> subBoxSeen(m, vector<bool>(n, false));

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] != '.'){
                    // number found in board
                    int number = board[i][j] - '1';

                    int k =  (i/3)*3 + j/3  ;// subbox number
                    // now check if number is seen somehwere
                    bool foundInRow = rowSeen[i][number];
                    bool foundInCol = colSeen[j][number];
                    bool foundInSubBox = subBoxSeen[k][number];

                    if(foundInRow || foundInCol || foundInSubBox){
                        // not a valid sudoku 
                        // as this number is repeated
                        return false;
                    }
                    else{
                        rowSeen[i][number] = true;
                        colSeen[j][number] = true;
                        subBoxSeen[k][number] = true;

                    }
                }
            }
        }

        return true;

        
    }
};