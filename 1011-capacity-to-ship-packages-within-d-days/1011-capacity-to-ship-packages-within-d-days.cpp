class Solution {
public:
    bool isvalid(int mid, vector<int> &weights, int D){
        // we wish to wish all weights using a ship whose max capacity = mid 
        // in D days
        
        int reqDays = 1;
        int sum = 0;
        for(int i = 0 ; i < weights.size() ; i++){
            sum += weights[i];
            if(sum > mid){
                sum = weights[i];
                reqDays++;
            }
            if(reqDays > D){
                return false;
            }
        }
        
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        
        int l = 0;
        int r = 0;
        
        for(int i = 0 ; i < n ; i++){
            l = max(l, weights[i]);
            r += weights[i];
        }
        
        int ans = -1;
        while(l<=r){
            int mid = l + (r-l)/2;
            // cout << "mid = " << mid << endl;
            // mid represnts the capacity of our probable ship 
            if(isvalid(mid, weights, days)){
                // since we gotta decrease/minimise the weight
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