class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int elem = nums[0];
        int freq = 0;

        for(auto &x : nums){
            if(freq == 0){
                elem = x;
            }
            
            if(x == elem){
                freq++;
            }
            else{
                freq--;
            }

            
        }

        return elem;
        
    }
};