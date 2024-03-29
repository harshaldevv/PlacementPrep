class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int n = intervals.size();
        ans.push_back(intervals[0]);
        
        for(int i = 1 ; i < n ; i++){
            auto curr = intervals[i];
            auto prev = ans.back();
            
            if(prev[1] >= curr[0]){
                ans.back()[1] = max(curr[1], prev[1]);
            }
            else{
                ans.push_back(curr);
            }
        }
        
        return ans;
        
    }
};