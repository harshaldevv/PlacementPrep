class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        
        int ans = 0;
        
        for(auto &x : nums){
            ans ^= x;
        }
        
        int index = -1;
        for(int i = 0 ;i < 32 ; i++){
            if( ans >> i & 1){
                // ith bit set
                index = i;
                break;
            }
        }
        
        
        vector<int> answer(2, 0);
        
        for(auto &x : nums){
            if( x >> index & 1){
                // bit is set;
                answer[0] ^=x;
                // xor isliye kyuki -> baaki numbers duplicate hai
                // so woh apne hat jayenge xor karte karte and 
                // ek hi aisa number bachega jiski index-th bit set hai
            }
            else{
                answer[1] ^=x;
                // xor isliye kyuki -> baaki numbers duplicate hai
                // so woh apne hat jayenge xor karte karte and 
                // ek hi aisa number bachega jiski index-th bit set NAHI hai
            }
        }
        
        return answer;
        
        
    }
};