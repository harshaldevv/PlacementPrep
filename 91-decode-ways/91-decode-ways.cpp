class Solution {
public:
    
    int numDecodings(string s) {
        if(s.size() == 0){
            return 1;
        }
        
        // return helper(s, 0);
        vector<int> dp(s.size() +1, -1);
        return helperWithMemo(s, 0, dp);
        
    }
    
    int helper(string s, int i){
        
        if( i == s.size()){
            return 1;
            //we've reached the end of the string 
        }
        
        
        if(s[i] == '0'){
            return 0;
        }
        
        long way1 = helper(s, i+1);
        long way2 = 0;
        if( i < s.size() -1 && (s[i] == '1' || s[i] == '2' && s[i+1] <'7')){
            way2 = helper(s, i+2);
        }
        
        return way1 + way2;
        
    }
    
    int helperWithMemo(string s, int i , vector<int> &dp){
        if(i == s.size()){
            dp[i] = 1;
            return 1;
        }
        if(s[i] == '0'){
            dp[i] = 0;
            return 0;
        }
        
        if(dp[i] != -1){
            return dp[i];
        }
        
        long way1 = helperWithMemo(s, i+1, dp);
        long way2 = 0;
        if( i < s.size() -1 && (s[i] == '1' || s[i] == '2' && s[i+1] <'7')){
            way2 = helperWithMemo(s, i+2, dp);
        }
        
        dp[i] = way1+ way2;
        return dp[i];
    }
};