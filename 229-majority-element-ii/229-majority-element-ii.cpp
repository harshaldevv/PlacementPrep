class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        // Hint - How many majority elements could it possibly have
        // Ans - maximum 2 majority elements --> Therefore try doing it in constant space complexity
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        

        
        unordered_map<int, int> mp;
        unordered_map<int, int> mp2;
        
        int n = nums.size();
        
        vector<int> ans;
        
        for(int i = 0 ; i < n; i++){
        
            mp[nums[i]]++;
        }
        
        for( auto it : mp){
            if(it.second > n/3){
                ans.push_back(it.first);
                // mp2[it.first]++;
            }
        }
        
        
        // for(auto it : mp2){
        //     ans.push_back(it.first);
        // }
        return ans;
        
    }
};