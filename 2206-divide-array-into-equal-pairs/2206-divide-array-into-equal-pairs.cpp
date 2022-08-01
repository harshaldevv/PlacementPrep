class Solution {
public:
    bool divideArray(vector<int>& nums) {
        // vector<int> counter(500+1, 0);
        unordered_map<int,int> mp;
        
        bool startPrint = false;
        
        for(int i = 0 ; i < nums.size(); i++){
            
            int x = nums[i];
           
            
            mp[x]++;
        }
        
        int totalPairs = 0;
        
        for(auto it : mp){
            totalPairs += it.second/2;
        }
        
        return totalPairs == nums.size()/2;
        
    }
};