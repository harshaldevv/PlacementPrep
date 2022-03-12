class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        return helper(numRows, ans);
        
    }
    
    vector<vector<int>> helper(int n, vector<vector<int>> res){
        if(n==1){
            vector<int> s;
            s.push_back(1);
            res.push_back(s);
            return res;
        }
        if(n==2){
            
            vector<int> s1;
            s1.push_back(1);
            
            vector<int> s2;
            s2.push_back(1);
            s2.push_back(1);
            
            res.push_back(s1);
            res.push_back(s2);
            
            return res;
        }
        
        
        res = helper(n-1, res);
        
        vector<int> temp;
        temp.push_back(1);
        // for loop
        vector<int> last_vector = res.back();
        for(int i = 0 ; i < last_vector.size() -1 ;i++){
            int x = last_vector[i] + last_vector[i+1];
            temp.push_back(x);
        }
        
        temp.push_back(1);
        
        res.push_back(temp);
        
        return res;
    }
};