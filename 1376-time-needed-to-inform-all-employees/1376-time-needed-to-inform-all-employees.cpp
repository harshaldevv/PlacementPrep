class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        int t = 0;
        // BFS
        // pehle graph banao
        vector<vector<int>> adjList(n);
        
        for(int i = 0 ;  i < n ; i++){
            if(manager[i] != -1){
                adjList[manager[i]].push_back(i);    
            }
        }
        
        queue<vector<int>> q;
        q.push({headID,0});
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto front = q.front();
                q.pop();
                int parent = front[0];
                int currTime = front[1];
                
                t = max(t, currTime + informTime[parent]);
                
                for(auto &child : adjList[parent]){    
                    q.push({child, currTime + informTime[parent]} );
                }
            }
        }
        
        return t;
        
    }
};