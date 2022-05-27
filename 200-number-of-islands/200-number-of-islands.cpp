class Solution {
public:
    void dfs(vector<vector<char>> &graph, int i , int j){
        if( i < 0 || i >= graph.size() || j < 0 || j >= graph[0].size() || graph[i][j] != '1'){
            return;
        }
        
        graph[i][j] = '2'; // marking as visited;
        
        dfs( graph,  i   , j-1 );
        dfs( graph,  i   , j+1 );
        dfs( graph,  i-1 , j   );
        dfs( graph,  i+1 , j   );
        
        return ;
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        
        for(int i = 0 ; i < grid.size(); i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        
        return count;
        
    }
};