class Solution {
public:
    bool isvalid(int &i, int &j, int &m ,int &n){
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    
    void dfs(vector<vector<int>> &heights, int i, int j, vector<vector<bool>> &ocean){
        int m = heights.size();
        int n = heights[0].size();
        
        if(!isvalid(i,j,m,n)){
            return ;
        }
        
        if(ocean[i][j] == true){
            return ; // already visited
        }
        
        ocean[i][j] = true;
        
        vector<int> dir{1,0,-1, 0, 1};
        for(int k = 0 ; k < 4 ; k++){
            int newx = i + dir[k];
            int newy = j + dir[k+1];
            if(isvalid(newx, newy, m,n) && !ocean[newx][newy] && heights[newx][newy] >= heights[i][j]){
                dfs(heights, newx, newy, ocean);                
            }   
        }
        return ;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        vector<vector<int>> ans;
        
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<bool>> alt(m, vector<bool>(n, false));
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        
        for(int i = 0 ; i < m ; i++){
            dfs(heights, i, 0, pacific);
            dfs(heights, i, n-1, alt);
        }
        
        for(int j = 0 ; j < n ; j++){
            dfs(heights, 0, j, pacific);
            dfs(heights, m-1, j, alt);
        }
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(alt[i][j] && pacific[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        
        return ans;
        
    }
};