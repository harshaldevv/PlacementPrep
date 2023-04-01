class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;
        
        vector<int> t(1,1);
        ans.push_back(t);
        
        for(int n = 2 ; n <= numRows ; n++){
            vector<int> temp(n, 1);
            auto last = ans.back();
            
            for(int i = 0 ; i < last.size() -1 ; i++){
                temp[i+1] = last[i] + last[i+1];
            }
            
            ans.push_back(temp);
        }
        
        return ans;
        
    }
};