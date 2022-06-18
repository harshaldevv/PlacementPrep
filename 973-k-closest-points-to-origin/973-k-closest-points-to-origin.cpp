#define p pair<int, pair<int, int>> 
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // maxheap 
        // of  pair<int, pair<int,int>>;
        
        // make max heap
        priority_queue<p> maxHeap;
        
        //put elements in maxHeap
        
        for(auto &elem : points){
            int x = elem[0];
            int y = elem[1];
            long dist = x*x + y*y;
            
            maxHeap.push({dist, {x,y}});
            
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        
        vector<vector<int>> ans;
        
        while(!maxHeap.empty()){
            auto elem = maxHeap.top();
            maxHeap.pop();
            
            int x = elem.second.first;
            int y = elem.second.second;
            
            ans.push_back({x,y});
        }
        
        return ans;
    }
    
};