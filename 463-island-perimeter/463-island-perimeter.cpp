class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int island = 0;
        int neighbour = 0;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    island++;
                    if(i+1 < n && grid[i+1][j] == 1){ // down neighbour
                        neighbour++;
                    }
                    if(j+1 < m && grid[i][j+1] ==1){ // right neigbour
                        neighbour ++;
                    }
                }
                
            }
        }
        
        return 4*island - 2 * neighbour;
        
    }
};