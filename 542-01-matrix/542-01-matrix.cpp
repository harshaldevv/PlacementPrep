class Solution {
public:
    bool isValid(int i, int j, vector<vector<int>>& mat){
        if(i< 0 || j < 0 || i >= mat.size() || j >= mat[0].size()){
            // invalid coordinates
            return false;
        }
        return true;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        // push all zeroes in queue instead of 1
        
        int m = mat.size();
        int n = mat[0].size();
        
        
        queue<pair<int, int>> q;
        vector<vector<int>> dist(m, vector<int>(n, -1));
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] == 0){
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        
        int dir[] = { +1, 0, -1, 0, +1};
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto f = q.front();
                q.pop();
                
                int currx = f.first;
                int curry = f.second;
                
                for(int k = 0 ; k < 4 ; k++){
                    int newx = currx + dir[k];
                    int newy = curry + dir[k+1];
                    
                    if(isValid(newx, newy, mat) && dist[newx][newy] ==-1){
                        dist[newx][newy] = dist[currx][curry]+1;
                        q.push({newx, newy});
                    }
                }
            }
        }
        
        return dist;
        
    }
};