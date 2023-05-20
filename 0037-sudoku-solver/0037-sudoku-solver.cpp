class Solution {
public:
    bool checker(vector<vector<char>>& board, int n, char &ch, int r, int c){
             
        // row check
        for(int j = 0 ; j < 9 ; j++){
            if(board[r][j] == ch){
                return false;
            }
        }
        
        // col check
        for(int i = 0 ; i < 9 ; i++){
            if(board[i][c] == ch){
                return false;
            }
        }
        
        
        int R = (r/3) * 3;
        int C = (c/3) * 3;

        
        // // check in the 3x3 box pehle
        // // this works too
        // for(int p = R; p < R+3 ; p++){
        //     for(int q = C ;  q < C+3 ; q++){
        //         if(board[p][q] == ch){
        //             return false;
        //         }
        //     }
        // }
        
        // check in the 3x3 box pehle
        for(int p = 0; p < 3 ; p++){
            for(int q = 0 ;  q < 3 ; q++){
                if(board[R + p][C + q] == ch){
                    return false;
                }
            }
        }
        
        return true;
    }
    bool helper(vector<vector<char>>& board, int n){
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] == '.'){
                    for(char c = '1' ; c <= '9' ; c++){
                        
                        if(checker(board, n, c, i, j)){
                            board[i][j] = c;
                            
                            if(helper(board, n)){
                                //since we only want one valid ans
                                // isliye we return true as soon as we know we 
                                // solve the board once
                                return true;
                                
                                // had we require all possible solutions
                                // hum if hata de bas likhte "helper(board,n)"
                            }
                            else{
                                //backtrack
                               board[i][j] = '.'; 
                            }
                            
                            //backtrack
                            // board[i][j] = '.';
                        }
                    }
                    
                    //exhausted all numbers, toh ab return false kardo
                    return false;
                }
            }
        }
        
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        
        int n = board.size();
        
        helper(board, n);
        
        return ;
        
    }
};