class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // heap --> cuz of "k"
        // pair ki feeling ie number, freq
        
        // min heap --> cuz hume min freq wale elements ko nikalte rehna hai
        // and then last me jo bachenge woh max freq wale honge
        
        vector<int> ans;
        
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        unordered_map<int, int> mp;
        for(auto &x : nums){
            mp[x]++;
        }
        
        for(auto &it : mp){
            pq.push({it.second, it.first});
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        // int indx = k-1;
        
        while(!pq.empty()){
            // ans[indx] = pq.top().second;
            ans.push_back(pq.top().second);
            // indx--;
            pq.pop();
        }        
        
        return ans;
    }
};