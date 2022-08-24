class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        set<pair<int, int>> SET;
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        int l = 0;
        int r = 0;
        
        while(l < n && r < n){
            if(nums[r] - nums[l] == k && l != r){
                SET.insert({nums[l], nums[r]});
                l++;
                r++;
            }
            else if(nums[r] - nums[l] >  k){
                l++;
            }
            else{
                r++;
            }
        }
        
        
        return SET.size();
    }
};