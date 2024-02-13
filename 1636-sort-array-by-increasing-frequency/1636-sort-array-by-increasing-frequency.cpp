class Solution {
public:
    
class Compare {
public:
    bool operator()(pair<int, int> a, pair<int, int>b){
       if(a.first == b.first){
           return a.second < b.second;
       }
        else{
            return a.first > b.first;
        }   
    }
};
    
    vector<int> frequencySort(vector<int>& nums) {
        
        // minheap with custom comp
        
        unordered_map<int, int> mp;
        
        
        for(auto &x : nums){
            mp[x]++;
        }
        
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        
        
        for(auto &x : mp){
            int f = x.second;
            int numb = x.first;
            
            pq.push({f, numb});
        }
        
        vector<int> ans;
        
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            int f = t.first;
            int numb = t.second;
            while(f--){
                ans.push_back(numb);    
            }
        }
        
        return ans;
        
    }
};