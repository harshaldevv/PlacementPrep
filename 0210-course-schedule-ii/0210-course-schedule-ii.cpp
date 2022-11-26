class Solution {
public:
    bool cycledetected(int &curr, vector<bool> &vis, vector<bool> &dfsvis, vector<vector<int>> &adjList){
        
        vis[curr] = true;
        dfsvis[curr] = true;
        
        for(auto &next : adjList[curr]){
            if(!vis[next]){
                if(cycledetected(next, vis, dfsvis, adjList)){
                    return true;
                }
            }
            else if(dfsvis[next]){
                //already visited
                return true;
            }
        }
        
        dfsvis[curr] = false;
        return false;
    }
    
    void toposort(int &curr, vector<vector<int>> &adjList, vector<bool> &vis, stack<int> &st){
        
        vis[curr] = true;
        
        for(auto &next : adjList[curr]){
            if(!vis[next]){
                toposort(next, adjList, vis, st);
            }
        }
        
        st.push(curr);
        return ;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        // detect cycle in a directed graph (dfsvis wala method)
        // if(cycledetected) -> return empty array
        // else do toposort(dfs wali)
        
        vector<int> ans;
        
        int n = numCourses;
        
        //make adjList
        
        vector<vector<int>> adjList(n);
        
        for(int i =  0 ; i < prerequisites.size() ; i++){
            int pehle = prerequisites[i][1];
            int baadme = prerequisites[i][0];
            
            adjList[pehle].push_back(baadme);
        }
        
        vector<bool> vis(n, false);
        vector<bool> dfsvis(n, false);
        
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                if(cycledetected(i, vis, dfsvis, adjList)){
                    // return true;
                    return ans; //empty array return krni hai
                }
            }
        }
        
        // do toposort
        
        stack<int> st;
        
        vector<bool> newVis(n, false);
        
        for(int i = 0 ; i < n ; i++){
            if(!newVis[i]){
                toposort(i, adjList, newVis, st);
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
        
    }
};