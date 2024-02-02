class Solution {
public:
    
    int check(int &weightOfShip, vector<int> &nums, int &D){
        int d = 1;
        int shipLoad = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            shipLoad += nums[i];
            if(shipLoad > weightOfShip){
                d++;
                shipLoad = nums[i];
            }
        }
        
        return d;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        int n = weights.size();
        
        int l = INT_MIN;
        int r = 0;
        
        int ans = -1;
        
        for(int i = 0 ; i < n ; i++ ){
            l = max(l, weights[i]);
            r += weights[i];
        }
        
        while(l<=r){
            int mid = l + (r-l)/2; // our SHIP WEIGHT
            
            int tempDays = check(mid, weights, days);
            
            if(tempDays <= days){
                ans = mid;
                // go left as we want lesser weight, as our shipment is succesful
                // in <= days, so we need a tighter bound aka lesser weight
                r = mid-1;
            }
            else if(tempDays > days){
                //weight is less,
                // increase weight
                l = mid+1;
            }
        }
        
        return ans;
    
    }
};