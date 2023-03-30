class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        //hci research 
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && dfs(board, word, visited, i, j, 0))
                    return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int i, int j, int k) {
        if (k == word.length())
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] != word[k])
            return false;
        visited[i][j] = true;
        bool res = dfs(board, word, visited, i-1, j, k+1) ||
                   dfs(board, word, visited, i+1, j, k+1) ||
                   dfs(board, word, visited, i, j-1, k+1) ||
                   dfs(board, word, visited, i, j+1, k+1);
        visited[i][j] = false;
        return res;
    }
};
