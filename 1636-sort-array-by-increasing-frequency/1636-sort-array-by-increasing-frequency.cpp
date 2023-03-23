class Solution {
public:
    class compareFunc{
        public:
        bool operator()(pair<int,int> &a, pair<int,int> &b){
            if(a.first== b.first){
                return a.second < b.second;
            }
            else{
                return a.first > b.first;
            }
            
        }
    };
    vector<int> frequencySort(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        
        for(auto &x :nums){
            mp[x]++;
        }
        
        // // hitesh way
        // sort(nums.begin(), nums.end(), [&](auto &a, auto &b)->bool{
        //     if(mp[a] == mp[b]){
        //         return a > b;
        //     }
        //     else{
        //         return mp[a] < mp[b];
        //     }
        // });
        // return nums;
        
        //Myway
        priority_queue< pair<int,int> , vector<pair<int,int>>, compareFunc> pq;
        for(auto &x : mp){
            pq.push({x.second, x.first});
        }
        vector<int> ans;
        while(!pq.empty()){
            int f = pq.top().first;
            int e = pq.top().second;
            while(f--){
                ans.push_back(e);    
            }
            
            pq.pop();
        }
        
        return ans;
        
        
        
        
        
    }
};