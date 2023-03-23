class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        //maxheap
        

        priority_queue<pair<int,pair<int,int>>> pq;            
        
        for(int i = 0 ; i < points.size() ; i++){
            int d = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            pq.push({d, {points[i][0], points[i][1]} });
            
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        vector<vector<int>> ans;
        
        while(!pq.empty()){
            auto topp = pq.top();
            int x = topp.second.first;
            int y = topp.second.second;
            ans.push_back({x,y});
            pq.pop();
        }
        return ans;
        
    }
};