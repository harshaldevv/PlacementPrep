class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //hci research 
        sort(intervals.begin(), intervals.end()); // sort intervals based on start time
        vector<vector<int>> merged;
        for (auto interval : intervals) {
            if (merged.empty() || interval[0] > merged.back()[1]) {
                // no overlap with the last interval in merged, add to merged
                merged.push_back(interval);
            } else {
                // overlap with the last interval in merged, merge the two intervals
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;
    }
};
