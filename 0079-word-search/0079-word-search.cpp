class Solution {
public:
    bool isvalid(int &i, int &j, int &m, int &n){
        return i >=0 && i < m && j >=0 && j < n;
    }
    bool dfs(int &i, int &j, string &word, vector<vector<char>> &board, int wordIndex, int &m, int &n){
        
        char originalWord = board[i][j];
        
        // cout << "i, j, char = " << i <<", " << j << ", " << board[i][j] << endl;
        
        board[i][j] = '#';
        
        if(wordIndex  == word.size()){
            return true;
        }
        
        vector<int> dir({1,0,-1,0,1});
        for(int k = 0 ; k < 4 ; k++){
            int newx = i + dir[k];
            int newy = j + dir[k+1];
            
            if(isvalid(newx, newy,m ,n) && board[newx][newy] != '#' && board[newx][newy] == word[wordIndex]){
                if(dfs(newx, newy, word, board, wordIndex +1, m, n)){
                    return true;
                }
            }
        }
        
        board[i][j] = originalWord;
        return false;
        
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        bool ans = false;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] == word[0]){
                    ans = dfs(i, j, word, board, 0+1, m, n);
                    if(ans == true){
                        return true;
                    }
                }
            }
        }
        
        return ans;
        
    }
};