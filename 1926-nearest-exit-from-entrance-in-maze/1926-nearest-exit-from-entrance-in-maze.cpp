class Solution {
public:
    bool isvalid(int i, int j ,vector<vector<char>>& maze ){
        if(i < 0 || j < 0 || i >= maze.size() || j >= maze[0].size()){
            return false;
        }
        return true;
    }
    
    bool boundarycell(int i, int j, vector<vector<char>>& maze  ){
        int m = maze.size();
        int n = maze[0].size();
        int dir[] = {+1, 0, -1, 0, +1};
        
        if(maze[i][j] == '.'){
            if(i == 0 || j == 0 || i == m-1 || j == n-1){
                return true;
            }
        }
        
        return false;
        
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int m = maze.size();
        int n = maze[0].size();
        
        int x = entrance[0];
        int y = entrance[1];
        
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        
        queue<pair<int, int>> q;
        q.push({x,y});
        vis[x][y] = true;
        
        int steps = 0;
        
        int dir[5] = { +1, 0, -1, 0, +1};
        
        while(!q.empty()){
            int sz = q.size();
            steps++;
            while(sz--){
                auto f = q.front();
                q.pop();
                
                int currx = f.first;
                int curry = f.second;
                
                // cout << "current = ( " << currx << " , " << curry << " )" << endl; 
                
                if( (currx != x) || (curry != y)){
                    // cout << " here " << currx << " , " << curry << endl;
                    if(boundarycell(currx, curry, maze)){
                        return steps-1;
                    }
                }
                // cout <<"hello " << endl;
                
                
                for(int k = 0 ; k < 4 ; k++){
                    int newx = currx + dir[k];
                    int newy = curry + dir[k+1];
                    
                    if(isvalid(newx, newy,maze) && maze[newx][newy] != '+' && !vis[newx][newy]){
                        q.push({newx, newy});
                        vis[newx][newy] = true;
                    }
                }
                
            }
        }
        
        return -1;
        
        
        
    }
};