class MyComp{
    public :
        bool operator()( pair<int, string> &p1,  pair<int, string> &p2){

            if(p1.first == p2.first){
                return p1.second < p2.second;
            }
            else{
                return  p1.first > p2.first;
            }
        }
};

class Solution {
public:  
    vector<string> topKFrequent(vector<string>& words, int k) {
        // min heap
        // cuz we want to remove the smallest frequencies, 
        // therefore min heap, cuz upar jo bachenge woh smaller frequncies hogi, 
        // therefore unko pop kardo
        
        unordered_map<string, int> mp;
        
        for(auto &x : words){
            mp[x]++;
        }
        
        
        
        priority_queue< pair<int, string> ,vector<pair<int, string>>, MyComp> pq; // min heap
        // {freq, element}
        
        for(auto & it : mp){
            
            string s = it.first;
            int freq = it.second;
            
            pq.push({freq, s});
            
            if(pq.size()>k){
                pq.pop();
            }
            
        }
        
        vector<string> ans(k);
        int i = k-1;
        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();
            
            ans[i] = front.second;
            i--;
        }
        
        // sort(ans.begin(), ans.end());
        
        return ans;
        
    }
};

