class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // min heap
        unordered_map<int, int> mp;

        for(auto &x : nums){
            mp[x]++;
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        for(auto &[val, freq] : mp){
            cout << "val = " << val << ", freq = " << freq << endl;
            pq.push({freq, val});

            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int> ans;
        while(pq.size() > 0){
            ans.push_back(pq.top()[1]);
            pq.pop();
        }

        return ans;


        
        
    }
};