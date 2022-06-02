class Solution {
public:
    void dfs(int currvertex, int n, vector<vector<int>>& graph, vector<int> &path, vector<vector<int>> & ans){
        
        path.push_back(currvertex);
        
        if(currvertex == n-1){
            ans.push_back(path);
        }
        
        for(auto x : graph[currvertex]){
            dfs(x, n, graph, path, ans);
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        // vector<bool> vis(n, false);
        vector<int> path;
        vector<vector<int>> ans;
        dfs(0, n, graph, path, ans);
            
        return ans;
        
    }
};