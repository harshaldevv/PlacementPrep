class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        
        ans.push_back(intervals[0]);
        
        for(int i = 1 ; i < n ; i++){
            if(ans.back()[1] >=intervals[i][0]){
                
                // merge but with caution
                
                // ans.back()[1] = intervals[i][1]; 
                // this wont work cuz if intervals[i][1] < ans.back()[1], and if still we swap them
                // --> leads to WA 
                // therefore we need to check as seen below
                
                if( intervals[i][1] < ans.back()[1] ){
                    // do nothing
                }
                else{
                    ans.back()[1] = intervals[i][1];
                }
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        
        return ans;
    }
};
