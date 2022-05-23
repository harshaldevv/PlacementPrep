class Solution {
public:
    void dfs(vector<vector<char>> &grid, int x , int y){
        if(grid[x][y] != 'O'){
            return ;
        }
        
        grid[x][y] = '#';
        
        int dx[] = {0, 0, -1, +1};
        int dy[] = {-1, +1, 0, 0};
        
        int newX, newY;
        for(int i = 0 ; i < 4 ; i++){
            newX = x + dx[i];
            newY = y + dy[i];
            if(newX >= 0  && newX < grid.size() && newY >= 0 && newY< grid[0].size()){
                // valid coordinates
                // cout << "newX = " << newX << " , " << "newY = " << newY << endl;
                dfs(grid, newX, newY);
                // cout<<"Above done " << endl;
            }
        }
        
        return;
    }
    void solve(vector<vector<char>>& board) {
        
        // apply boundary dfs
        
        // any 'O' on the boundary shouldnt be flipped 
        // therefore find such O and mark them as '#'
        // and also find those O which are connected to such O
        // and mark them as #
        
        int m = board.size();
        int n = board[0].size();
        // cout << "here 2" << endl;
        // first row
        for(int i = 0 ; i < n ; i++){
            if(board[0][i] == 'O'){
                dfs(board, 0, i);
            }
        }
        // cout << "here " << endl;
        // last row
        for(int i = 0 ; i < n ; i++){
            if(board[m-1][i] == 'O'){
                dfs(board, m-1, i);
            }
        }
        
        // first col
        for(int i = 0 ; i < m ; i++){
            if(board[i][0] == 'O'){
                dfs(board, i, 0);
            }
        }
        
        // last col
        for(int i = 0 ; i < m ; i++){
            if(board[i][n-1] == 'O'){
                dfs(board, i, n-1);
            }
        }
        
        
        // now traversing the whole matrix
        
        for(int i = 0. ; i < m ; i++){
            for(int j = 0  ; j < n ; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
        
        return ;
        
        
    }
};