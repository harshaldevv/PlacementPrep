class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        unordered_map<int, int> mp;
        
        for(auto &x: arr){
            mp[x]++;
        }
        
        vector<vector<int>> v;
        for(auto &x : mp){
            int e = x.first;
            int f = x.second;
            v.push_back({f, e});
        }
        
        sort(v.begin(), v.end());
        
        int n = v.size();
        int ans = mp.size();
        
        int t = k;
        
        int i = 0;
        
        while (i < n ){
            // cout << "t = " << t << endl;
            // cout << "v[i][0] = " <<v[i][0] << endl;
            // cout << "t - v[i][0] = " << t - v[i][0] << endl;
            // cout << "ans = " << ans << endl;
            // cout << "v[i][1] = " << v[i][1] << endl;
            // cout << endl;
            if(t - v[i][0] >0){
                t-= v[i][0];
                ans--;
                
                i++;
                
            }
            else if(t - v[i][0]  == 0){
                ans--;
                break;
            }
            else{
                break;
            }
        }
        
        return ans;
        
    }
};