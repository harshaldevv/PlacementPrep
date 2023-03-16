class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        // hci research
        
        vector<vector<int>> res;
        vector<int> path;
        dfs(graph, 0, path, res);
        return res;
    }
    
private:
    void dfs(vector<vector<int>>& graph, int node, vector<int>& path, vector<vector<int>>& res) {
        path.push_back(node);
        if (node == graph.size() - 1) {
            res.push_back(path);
        } else {
            for (int neighbor : graph[node]) {
                dfs(graph, neighbor, path, res);
            }
        }
        path.pop_back();
    }
};
