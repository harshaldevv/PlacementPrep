class Solution {
public:
    vector<string> code(int n){
        if(n==1){
            return {"0", "1"};
        }
        
        vector<string> prev = code(n-1);
        
        vector<string> ans;
        
        for(auto x : prev){
            string s = "0" + x;
            ans.push_back(s);
        }
        for(int i = prev.size() -1 ; i >= 0 ; i--){
            string s = "1" + prev[i];
            ans.push_back(s);
        }
        
        return ans;
    }
    vector<int> grayCode(int n) {
        
        vector<string> stringAns;
        stringAns = code(n);
        
        vector<int> ans;
        for(auto x : stringAns){
            int numb = stoi(x,0,2);
            ans.push_back(numb);
        }
        
        return ans;
        
    }
};