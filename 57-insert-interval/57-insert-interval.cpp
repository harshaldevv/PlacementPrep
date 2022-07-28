class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> ans;
        int n = intervals.size();
        
        int i = 0;
        
        // push intervals that dont overlap with the newInterval and lie before newInterval
        for( ; i < n ; i++){
            if(intervals[i][1] < newInterval[0]){
                // endtime of my ith interval < newInterval's start time
                // push these intervals -->as they are obviously non-overlapping
                
                ans.push_back(intervals[i]);
            }
            else{
                break;
            }
        }
        
        cout << "i = " << i << endl;
        // merge the overlapping intervals
        for( ;i < n ; i++){
            int a = intervals[i][0];
            int b = intervals[i][1];
            
            int c = newInterval[0];
            int d = newInterval[1];
            
            if(  max(a,c) <= min(b,d)) {
                // merge hoga
                
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
                
                cout <<"newInterval[0] = " <<newInterval[0] << endl;
                cout <<"newInterval[1] = " <<newInterval[1] << endl;
            }
            else{
                break;
            }
        }
        //push this one whole merged interval
        
        cout << "i = " << i << endl;
        ans.push_back(newInterval);
        
        // push all the intervals now, as these intervals lie on the right side of the newInterval
        for( ; i < n ; i++){
            ans.push_back(intervals[i]);
        }
        cout << "i = " << i << endl;
        
        return ans;
    }
};