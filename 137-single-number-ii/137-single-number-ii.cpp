class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        // every element appears three times except for one, which appears exactly once.
        
        
        /*
        https://leetcode.com/problems/single-number-ii/discuss/43297/Java-O(n)-easy-to-understand-solution-easily-extended-to-any-times-of-occurance
        */
        int ans = 0;
        for(int i = 0 ; i < 32 ; i++){
            
            int sum = 0;
            
            for(int j = 0 ; j < nums.size() ; j++){
                if( (nums[j]>>i & 1) == 1 ){
                    // counting set bits 
                    
                    // i th bit is 1
                    
                    sum++;
                }
            }
            
            sum %= 3;
            
            if(sum != 0){
                ans += sum << i; // += kardo ya |= (bitwise or) dono chal rahe hai
            }
            
        }
        
        return ans;
        
        
    }
};