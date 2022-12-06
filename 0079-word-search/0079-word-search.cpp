class Solution {
public:
    bool isvalid(vector<vector<char>> &board, int i, int j){
        int m = board.size();
        int n = board[0].size();
        
        if( i < 0 || j < 0 || i >= m || j>= n){
            return false;
        }
        
        return true;
    }
    bool startDfs(vector<vector<char>> &board, int i, int j, int indx, string &word){
        
        
        char originalChar = board[i][j];
        
        // if(originalChar != word[indx]){
        //     return false;
        // }
        
        if(indx +1 == word.size()){
            return true;
        }
        
        board[i][j] = '#'; // marking the cell visited by leaving our nishani
        
        int dir[] = {1,0,-1,0,1};
        
        for(int k = 0 ; k < 4 ; k++){
            int newx = i + dir[k];
            int newy = j + dir[k+1];
            
            if(isvalid(board, newx, newy) ){
                
                // indx + 1 < word.size() && board[newx][newy] == word[indx +1] 
                if(indx + 1 == word.size()){
                    return true;
                }

                if(board[newx][newy] == word[indx +1] ){
                    bool temp = startDfs(board, newx, newy, indx+1, word);
                    if(temp == true){
                        return true;
                    }
                }
                
            }
        }
        
        board[i][j] = originalChar ; // backtrack step
        
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        if(word == ""){
            return false; // kya hi search kare matrix me
        }
        
        
        
        bool ans = false;
        int indx = 0;
        for(int i = 0 ; i < m ;i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] == word[0]){
                    ans = startDfs(board, i,j , indx, word);
                    if(ans == true){
                        return ans;
                    }
                }
            }
        }
        
        return ans;
    }
};