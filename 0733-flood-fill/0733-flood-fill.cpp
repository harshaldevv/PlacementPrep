class Solution {
public:
    bool isValid(int &newx, int &newy, int &m, int &n){
        if(newx < 0 || newx >= m || newy < 0 || newy >= n){
            return false;
        }
        
        return true;
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if(image[sr][sc] == color){
            return image;
        }
        
        int m = image.size();
        int n = image[0].size();
        
        int orgColor = image[sr][sc]; // original Color
        queue<vector<int>> q;
        q.push({sr,sc});
        
        vector<int> dir{1,0,-1,0,1}; // direction array
        
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                auto front = q.front();
                q.pop();
                
                int tempX = front[0];
                int tempY = front[1];
                
                image[tempX][tempY] = color;
                
                for(int k = 0 ; k < 4 ; k++){
                    int newX = tempX + dir[k];
                    int newY = tempY + dir[k+1];
                    
                    // cout << "newX, newY = " << newX << " " << newY << endl;
                    
                    if(isValid(newX, newY, m, n) && image[newX][newY] == orgColor){
                        q.push({newX, newY});
                    }
                }
            }
        }
        
        return image;
        
    }
};