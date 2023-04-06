class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        
        
        int c1 = 0;
        int c2 = 0;
        int x1 = -1;
        int x2 = -1;
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == x1){
                c1++;
            }
            else if(nums[i] == x2){
                c2++;
            }
            else if(c1 == 0){
                x1 = nums[i];
                c1++;
            }
            else if(c2 == 0){
                x2 = nums[i];
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        
        //checking if e1 and e2 are actually me majority elements
        c1 = 0;
        c2 = 0;
        
        for(auto &x : nums){
            if(x == x1){
                c1++;
            }
            else if(x == x2){
                c2++;
            }
        }
        
        
        if(c1 > nums.size()/3){
            ans.push_back(x1);
        }
        
        if(c2 > nums.size()/3){
            ans.push_back(x2);
        }
        
        return ans;
    }
};