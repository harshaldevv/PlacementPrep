class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(), points.end(), cmp);
            
        int n = points.size();
        
        int ans = 1;
        
        auto temp = points[0];
            
        for(int i = 1 ; i < n ; i++){
            if(points[i][0] > temp[1]){
                //do something
                ans++;
                temp = points[i];
                // cout << "jere" << endl;
            }
            
        }
        
        return ans;
        
    }
};