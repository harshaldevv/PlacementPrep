class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        // hci research 
        int n = intervals.size();
        if (n == 0) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        int ans = 0, end = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < end) {
                ans++;
            } else {
                end = intervals[i][1];
            }
        }
        return ans;
    }
};
