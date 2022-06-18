#define pii pair<int, int>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // Trivial solution --  Sorting (TC - O(nlogn));
        
        // Heap --> Min Heap  --> TC O(nlogk), SC - O(N)
        priority_queue<pii, vector<pii>, greater<pii>> minheap;
        
        unordered_map<int, int> mp;
        for(auto &x : nums){
            mp[x]++;
        }
        
        //make heap from map;
        for(auto &x : mp){
            int elem = x.first;
            int freq = x.second;
            minheap.push({freq, elem});
            if(minheap.size() > k){
                minheap.pop();
            }
        }
        
        vector<int> ans;
        while(!minheap.empty()){
            auto TOP = minheap.top();
            minheap.pop();
            ans.push_back(TOP.second);
        }
        
        return ans;
        
        
    }
};