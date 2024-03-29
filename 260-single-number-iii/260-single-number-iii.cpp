class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        vector<int> ans(2,-1);
        ans[0] = nums[0];
        ans[1] = nums[1];
        
        
        // xorr of all elements --> now any arbit set bit of xorr 
        // --> now this same bit, it will set in A and unset in B
        // --> If bit_i in (a xor b) is 1, bit_i at a and b are different.
        
        int xorr = 0;
        
        for(auto &x : nums){
            xorr ^= x;
        }
        
        
        // find the first set bit from right
        int index = -1;
        for(int i = 0 ; i < 32 ; i++){
            if( (xorr & 1<<i) != 0 ){
                // ith bit set is SET --> therefore we do != 0 
                // we dont do == "1" --> bcz i-th bit  =1 hai toh jab & lenge toh
                // toh non zero number aata hai
                
                index = i;
                break;
            }
        }
        cout <<"xorr = " << xorr << "index = " << index << endl;
        
        //now divide elements in 2 groups
        // 1st group --> have the i-th bit = 1
        // 2nd group --> have the i-th bit = 0
        
        int first = 0;
        int second = 0;
        for(auto &x : nums){
            if( (x & 1<<index) ==0){
                // ith bit is not set 
                second ^= x;
            }
            else{
                first ^= x;
            }
        }
        
        ans[0] = first;
        ans[1] = second;
        

        
        return ans;
    }
};