class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // using heap
        // heap sort
        // min heap
        if(nums.size() <= 1){
            return nums;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto &x : nums){
            pq.push(x);
        }
        
        vector<int> ans;
        
        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            
            ans.push_back(top);
        }
        
        return ans;
        
    }
};