class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        
        int pro = 1;
        int maxPro = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            
            int x = nums[i];
            pro*= x;
            maxPro = max(maxPro, pro);
            if(pro == 0){
                pro = 1;
            }
            
        }
        
        
        int revPro = 1;
        int revMaxPro = INT_MIN;
        for(int i = n-1 ; i>=0;i--){
            int x = nums[i];
            revPro *= x;
            revMaxPro = max(revMaxPro, revPro);
            
            if(revPro == 0){
                revPro = 1;
            }
        }
        
        return max(maxPro, revMaxPro);
        
    }
};