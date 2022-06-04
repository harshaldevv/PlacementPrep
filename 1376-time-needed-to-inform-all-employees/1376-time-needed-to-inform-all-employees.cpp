class Solution {
public:
        // Method 1 --> normal dfs
//     int dfs(vector<vector<int>> &graph, int curr, vector<int> &informTime){
//         int t = 0;
        
//         for(auto x : graph[curr]){
//             t = max(t, dfs(graph, x, informTime));
//         }
        
//         return t + informTime[curr];
//     }
    
    //Method 2 --> DFS + Backtrack
    void DFS(int curr, vector<vector<int>> &graph, vector<int> &informTime, int &t, int &maxTime){
        maxTime = max(t, maxTime);
        
        for(auto x : graph[curr]){
            t += informTime[curr];
            //cout << " t = " << t << endl;
            DFS(x, graph, informTime, t, maxTime);
            t -= informTime[curr];
        }
        
        
        
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if(n==1){
            return 0;
        }

        
        // using dfs
        vector<vector<int>> graph(n);
        
        for(int i = 0 ; i < n ; i++){
            if(manager[i] == -1){
                continue;
            }
            else{
                graph[manager[i]].push_back(i); // directed graph from employee to boss
            }   
        }
        
        // return dfs(graph, headID, informTime);
        int t = 0;
        int maxT = 0;
        DFS(headID, graph, informTime, t, maxT);
        return maxT;
        
        
        
    }
};