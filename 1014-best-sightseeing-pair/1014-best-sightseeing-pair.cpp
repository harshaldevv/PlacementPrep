class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        
        int n = values.size();
        
        int prev = values[0] + 0;
        int res = prev + values[1] - 1;
        
        for(int i = 1 ; i < n ; i++){
            res = max(res, prev + values[i] - i);
            prev = max(prev, values[i] + i);
            
        }
        return res;
        
    }
};