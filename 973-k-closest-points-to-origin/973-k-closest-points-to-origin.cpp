class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // maxheap
        
        priority_queue<pair<int, pair<int, int>>> pq;
        
        for(auto & it : points){
            int x = it[0];
            int y = it[1];
            int dist = x*x + y*y;
            
            pq.push({dist, {x,y}});
            
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        vector<vector<int>> ans;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            // cout << top.second.first << " " << top.second.second << endl;
            // ans.push_back(top.second);
            int x = top.second.first;
            int y = top.second.second;
            
            ans.push_back({x,y});
        }
        
        return ans;
    }
};