class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        
        // min heap cuz we want minimum (or less) frequency wale 
        // elements pop out ho jaye
        // last me higher frequency wale reh jayengge
        
        unordered_map<int, int> mp;
        for(auto &x :nums){
            mp[x]++;
        }
        
        // min heap -- > {freq, element}
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(auto &it : mp){
            pq.push({it.second, it.first});
            
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        vector<int> ans;
        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();
            ans.push_back(front.second);
        }
        
        return ans;
    }
};