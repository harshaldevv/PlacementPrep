class Solution {
public:
    
    vector<string> helper(int n){
        if(n==1){
            return {"0", "1"};
        }
        
        vector<string> temp = helper(n-1);
        
        vector<string> ans ;
        
        for(int i = 0 ; i < temp.size() ; i++){
            string s = temp[i] + "0";
            ans.push_back(s);
        }
        
        
        for(int i = temp.size() -1 ; i >= 0  ; i--){
            string s = temp[i] + "1";
            ans.push_back(s);
        }
        
        return ans;
        
        
        
    }
    vector<int> grayCode(int n) {
        
        if(n==1){
            return {0,1};
        }
        
        vector<string> temp = helper(n);
        
        vector<int> ans;
        for(auto x : temp){
            ans.push_back(stoi(x,0,2));
        }
        
        return ans;
        
    }
};