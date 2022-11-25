class Solution {
public:
    void dfs(vector<vector<int>> &adjList, int &curr, vector<bool> &vis){
        
        vis[curr] = true;
        
        for(auto &next : adjList[curr]){
            if(!vis[next]){
                dfs(adjList, next, vis);
            }
        }
        
        return ;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        vector<bool> vis(n+1, false);
        vector<vector<int>> adjList(n+1);
        //make adj List
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i!=j && isConnected[i][j] == 1){
                    adjList[i].push_back(j);
                    adjList[i].push_back(i);
                }
            }
        }
        int ans = 0;
        for(int i  = 0 ; i < n ; i++){
            if(!vis[i]){
                dfs(adjList, i, vis);
                ans++;
            }
            
        }
        return ans;   
    }
};