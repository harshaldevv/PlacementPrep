class Solution {
public:
    bool isHelper(int i, int currColor, vector<int> &color, vector<vector<int>> &adj){
        // DFS

        color[i] = currColor;

        for(auto &child: adj[i]){
            if(color[child] == -1){
                // not visited
                if(!isHelper(child, !currColor, color, adj)){
                    return false;
                }
            }
            else if(color[child] == color[i]){
                // already visited and colored 
                // collision/clash found
                return false;
            }
            else if(color[child] != color[i]){
                // do nothing
                continue;
            }
        }

        return true;
    }

    bool BFS(int i, int currColor, vector<int> &color, vector<vector<int>> &adj){

        queue<int> q;
        
        q.push(i);
        color[i] = currColor; // mark visited

        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                auto frontt = q.front();
                q.pop();

                for(auto &child : adj[frontt]){
                    if(color[child] == -1){
                        // not visited
                        color[child] = !color[frontt]; // mark visited
                        q.push(child); // push to queue for further processing
                    }
                    else if(color[child] == color[frontt]){
                        // already visited
                        // collision found
                        return false;
                    }
                    else{
                        // different color than parent
                        // already visited
                        // do nothing
                    }
                }
            }
        }

        return true;

    }

    bool isBipartite(vector<vector<int>>& graph) {

        /*
        // DFS
        // int V = graph.size();
        // vector<int> color(V, -1);
        // // -1 = not visited
        // // 0 or 1 -> colored

        // for(int i = 0 ; i < V; i++){
        //     if(color[i] == -1){
        //         // not visited
        //         bool isPossible = isHelper(i, 0, color, graph);

        //         if(!isPossible){
        //             return false;
        //         }
        //     }
        // }

        // return true;
        */


        // BFS
        int V = graph.size();
        vector<int> color(V, -1);
        // -1 = not visited
        // 0 or 1 = visited

        for(int i = 0 ; i < V; i++){
            if(color[i] == -1){
                //not yet visited
                bool isPossible = BFS(i, 0, color, graph);

                if(!isPossible){
                    return false;
                }
            }
        }
        
        return true;
    }
};