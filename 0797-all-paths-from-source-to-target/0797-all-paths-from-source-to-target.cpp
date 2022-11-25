class Solution {
public:
    
    void dfs(vector<vector<int>> &graph, vector<int> &path, vector<vector<int>> &ans, int currvertex, int endvertex){
        
        if(currvertex > endvertex){
            return ; //hehe useless condition mene aise hi daaldia
        }
        
        path.push_back(currvertex);
        
        if(currvertex == endvertex){
            ans.push_back(path);
        }
    
        for(auto &x : graph[currvertex]){
            dfs(graph, path, ans, x, endvertex);
        }
        
        path.pop_back();
        
        return ;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> path;
        
        
        dfs(graph, path, ans, 0, n-1);
        
        return ans;
        
    }
};