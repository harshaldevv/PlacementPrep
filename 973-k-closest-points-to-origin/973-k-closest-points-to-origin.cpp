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
            vector<int> temp(2, -1);
            temp[0] = x;
            temp[1] = y;
            ans.push_back(temp);
        }
        
        return ans;
    }
};