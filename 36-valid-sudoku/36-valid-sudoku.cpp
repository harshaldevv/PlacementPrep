class Solution {
public:
    bool possible(vector<vector<char>>& board, char c, int ROW, int COL){
        // check rows
        for(int i = 0 ; i < 9 ; i++){
            if(i == ROW){
                continue;
            }
            if(board[i][COL] == c){
                cout << "here" << endl;
                return false;
            }
        }
        
        //check cols
        for(int j = 0 ; j < 9 ; j++){
            if(j == COL){
                continue;
            }
            if(board[ROW][j] == c){
                cout << "here 2 " << endl;
                return false;
            }
        }
        
        int r0 = (ROW/3)*3;
        int y0 = (COL/3)*3;
        
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                
                int x = r0 + i;
                int y = y0 + j;
                
                if( x == ROW && y == COL){
                    continue;
                }
                if(board[r0 + i ][y0 + j] == c){
                    
                    cout << "here 3 " << endl;
                    cout << "c = " << c  << endl;
                    cout << "r0 + i = " << r0 + i << endl;
                    cout << "y0 + j = " << y0 + j << endl;
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
                if(board[i][j] != '.'){
                    char c = board[i][j];
                    if(possible(board, c, i, j) == false){  
                        cout << "i = " << i << " , j = " << j << endl;
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return solve(board);
        
    }
};