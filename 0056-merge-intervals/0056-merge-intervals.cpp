class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        

        for(int i = 1 ; i < intervals.size(); i++){
            auto lastMeeting = ans.back();
            int lastMeetingStart = lastMeeting[0];
            int lastMeetingEnd = lastMeeting[1];
            int currMeetingStart = intervals[i][0];
            int currMeetingEnd = intervals[i][1];

            if(currMeetingStart <= lastMeetingEnd){
                // overlap found
                ans.back()[1] = max(ans.back()[1], currMeetingEnd);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }

        return ans;

        
    }
};