class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int count = 0;
        int numb = 0;
        
        for(int i = 0 ; i< nums.size(); i++){
            if(count == 0){
                numb = nums[i];
            }
            
            if(numb == nums[i]){
                count++;
            }
            else{
                count--;
            }
        }
        
        return numb;
        
//         unordered_map <int, int> mp;
        
//         int freq = -1;
//         int numb = INT_MIN;
        
//         for(int i = 0 ; i < nums.size();i++ ){
//             mp[nums[i]]++;
            
//             int internal_freq = mp[nums[i]];
//             if(internal_freq > freq){
//                 freq = internal_freq;
//                 numb = nums[i];
//             }
//         }
        
//         return numb;
        
        
    }
};