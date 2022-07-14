class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int target) {
        // 
        // max heap
        
        priority_queue<pair<int,int> > pq; // maxheap
        
        vector<int> ans;
        
        for(int i = 0 ; i < nums.size() ; i++){
            int diff = abs(target - nums[i]);
            pq.push({diff, nums[i]});
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            ans.push_back(top.second);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};