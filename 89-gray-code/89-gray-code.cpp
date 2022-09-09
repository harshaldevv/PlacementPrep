class Solution {
public:
    vector<int> grayCode(int n) {
        int p = 1 << n ;
        
        vector<int> ans;
        for(int i = 0 ; i < p ; i++){
            ans.push_back(i^(i/2));
        }
        
        return ans;
        
    }
};