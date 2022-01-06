class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int > mp;
        int n = nums.size();
        vector<int> ans;
        
        for(int i  = 0 ; i < n; i++){    
            int diff = target - nums[i];
            
            // cout << mp.find(diff) << endl;
            
            if(mp.find(diff) != mp.end()){
                ans.push_back(i);
                ans.push_back(mp[diff]);
                return ans;
            }
            
            mp.insert({nums[i], i});
        }
        
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};
















// unordered_map<int, int> map;
//         vector<int> answer;
        
//         for(int i = 0 ; i < nums.size() ; i++){
//             int numb1 = nums[i];
            
//             if(map.count(target - numb1) == 1){
//                 answer.push_back(i);
//                 answer.push_back(map[target-numb1]);
//                 return answer;
//             }
//             else{
//                 map.insert({nums[i], i});
//             }
            
//         }
        
//         return answer;
        
        