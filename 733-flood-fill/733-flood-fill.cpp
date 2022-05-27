class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int startColor){
        if(image[sr][sc] != startColor){
            return ;
        }
        else{
            image[sr][sc] = newColor;
        }
        
        int dx[4] = {0,0,-1,+1};
        int dy[4] = {-1, +1, 0, 0};
        
        for(int i = 0 ; i < 4 ; i++){
            
            int newX = sr + dx[i];
            int newY = sc + dy[i];
            
            if(newX >= 0 && newX < image.size() && newY >= 0 && newY < image[0].size()){
                // valid coordinates;
                dfs(image, newX, newY, newColor, startColor);
            }
        }
        
        return;
        
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int startColor = image[sr][sc];
        if(newColor == startColor){
            return image;
        }
        dfs(image, sr, sc, newColor, startColor);
        
        return image;
        
    }
};