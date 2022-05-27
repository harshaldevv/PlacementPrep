class Solution {
public:
    
    void dfs(int i, vector<vector<int>> &graph, vector<int> &path, vector<vector<int>> &ans){
        path.push_back(i);
        if(i == graph.size() -1){
            ans.push_back(path);
            //path.clear();
        }
        else{
            for(auto j : graph[i]){
                dfs(j, graph, path, ans);
                path.pop_back();  // hmm ye thora sochne wala step hai
            }
        }
        
        //path.pop_back();  // hmm ye thora sochne wala step hai

        return;
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(0, graph, path, ans);
        return ans;
    }
    
    
};