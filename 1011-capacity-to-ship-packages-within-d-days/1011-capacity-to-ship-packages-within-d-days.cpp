class Solution {
public:
    bool check(int &mid, vector<int> &weights, int &days){
        int D = 1;
        int s = 0;
        
        for(auto &x : weights){
            s += x;
            
            if(s > mid){
                D++;
                s = x;
            }
            if(D > days){
                return false;
            }
        }
        
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int l = 0;
        int r = 0;
        
        int ans = -1;
        
        for(auto &x : weights){
            l = max(l,x);
            r += x;
        }
        
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(check(mid, weights, days)){
                ans = mid;
                r = mid -1;
            }
            else{
                l = mid +1;
            }
        }
        
        return ans;
        
    }
};