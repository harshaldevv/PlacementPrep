class Solution {
public:
    vector<string> solve(int n){
        if(n == 1){
            return {"0", "1"};
        }
        
        vector<string> prev = solve(n-1);
        
        vector<string> ans;
        for(auto &x : prev){
            ans.push_back( "0" + x);
        }
        
        for(int i = prev.size() -1; i>=0 ; i--){
            ans.push_back("1" + prev[i]);
        }
        
        return ans;
    }
    vector<int> grayCode(int n) {
        
        vector<string> ans;
        
        ans = solve(n);
        
        vector<int> finalAns;
        
        for(auto &x : ans){
            int p = stoi(x, 0,2);
            finalAns.push_back(p);
        }
        
        
        return finalAns;
        
        
    }
};