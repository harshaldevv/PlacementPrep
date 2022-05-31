class Solution {
public:
    int dir[5] = { +1, 0, -1, 0, +1};
    
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis, queue<pair<int, int >> &q){
        if(i < 0 || j < 0 || i >= grid.size() || j>= grid[0].size()){
            // invalid coordinates
            return ;
        }
        if(vis[i][j]){
            // already visited
            return ;
        }
        if(grid[i][j] != 1){
            return; // pani ko thori hum apne queue me push krenge
        }
        
        vis[i][j] = true;
        grid[i][j] = 2;
        q.push({i, j});
        
        for(int k = 0 ; k < 4 ; k++){
            int newx = i + dir[k];
            int newy = j + dir[k+1];
            dfs(newx, newy, grid, vis, q); 
            // validity of newx and newy would automatically be checked in this recusrive call
        }
        
        return ;
        
        
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pair<int, int >> q;
        
        
        bool found = false;
        for(int i = 0 ; i < n ; i++){
            
            if(found){
                break;
            }
            
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    dfs(i, j, grid, vis, q);
                    found = true;
                    break;
                }
            }
        }
        
        // dfs done
        
        // now doing dfs
        // cout << "queue size = " << q.size() << endl;
        // cout <<"queue first elem = " << q.front().first << " " << q.front().second << endl;
        int steps = 0;
        while(!q.empty()){
            int sz = q.size();
            steps++;
            while(sz--){
                auto f = q.front();
                q.pop(); // nahi kia toh tle de dega lol
                int currx = f.first;
                int curry = f.second;
                
                if(grid[currx][curry] == 1 ){
                    return steps-2; 
                }
                
                
                
                for(int k = 0 ; k < 4 ; k++){
                    int newx = currx + dir[k];
                    int newy = curry + dir[k+1];
                    if(newx >= 0 && newy >= 0 && newx < n && newy < n && !vis[newx][newy]){
                        
                        //termination condition
                        // we''ve found the island 2 (ie a piece of land of island 2 is found , therefore return steps)
                
                        
                        
                        // termination condition couldnt be placed after currx and curry, cuz there was no way to check 
                        // if currx and curry are a part of island 2, 
                        // as even though i tried using 
                        q.push({newx, newy});
                        vis[newx][newy] = true;
                    }
                }
            }
        }
        return -1;
    }
};