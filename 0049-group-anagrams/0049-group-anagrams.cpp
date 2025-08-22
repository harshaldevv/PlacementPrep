class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int n = strs.size();

        if(n <=1){
            return {strs};
        }

        unordered_map<string, vector<string>> mp;
        for(auto &x: strs){
            auto currword = x;
            sort(x.begin(), x.end());

            mp[x].push_back(currword);
        }

        vector<vector<string>> ans;
        
        for(auto &x: mp){
            vector<string> temp;
            for(auto &w : x.second){
                temp.push_back(w);
            }
            ans.push_back(temp);
        }

        return ans;
        
    }
};