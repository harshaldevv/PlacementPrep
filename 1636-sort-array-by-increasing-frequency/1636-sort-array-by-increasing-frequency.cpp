#define pii pair<int, int>
class Solution {
public:
    class compare_fun{
        public :
        bool operator()(pii p1, pii p2){
            if(p1.first == p2.first){
                return p1.second < p2.second;
            }
            return p1.first > p2.first;
        }
    };
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto &x : nums){
            mp[x]++;
        }
        
        //min heap;
        
        priority_queue<pii, vector<pii>, compare_fun > minheap;
        
        for(auto &x : mp){
            int elem = x.first;
            int freq = x.second;
            minheap.push({freq, elem});
        }
        
        
        vector<int> ans;
        while(minheap.size() > 0){
            auto TOP = minheap.top();
            minheap.pop();
            int f = TOP.first;
            int e = TOP.second;
            while(f--){
                ans.push_back(e);
            }
            
        }
        
        return ans;
        
        
        
    }
};