class Solution {
public:
    bool isValid(int i, int j, int n, vector<vector<int>>& grid ){
        if(i>= 0 && j >=0 && i < n && j < n && grid[i][j] == 0){
            return true;
        }
        return false;
    }
    int maxDistance(vector<vector<int>>& grid) {
        int ans;
        
        int n = grid.size();
        
        queue<pair<int, int>> q;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j< n ; j++){
                if(grid[i][j] == 1){ 
                    // why land cell se search chalu
                    
                    // do something
                    // do bfs
                    q.push({i,j});
                }
            }
        }
        if(q.size() == n*n || q.size() == 0){ 
            // sara land hi land hai ya sara pani pani hai
            return -1;
        }
        
        ans = 0;
        
        while(!q.empty()){
            int sz = q.size();
            ans++;
            while(sz--){
                auto p = q.front();
                q.pop();
                
                int x = p.first;
                int y = p.second;
                
                int dir[] = {1,0,-1, 0, 1};
                for(int k = 0 ; k < 4 ; k++){
                    int newX = x + dir[k];
                    int newY = y + dir[k+1];
                    
                    if(isValid(newX, newY, n, grid)){
                        // is valid checks ki grid ke bahar toh nahi chala gaya
                        //and ki newX and newY pe pani haina 
                        q.push({newX, newY});
                        grid[newX][newY] = 2; // marking that water cell as visited
                    }
                }
            }
        }
        
        return ans-1;
        
    }
};