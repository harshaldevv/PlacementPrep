class Solution {
public:
    int check(vector<int> &weights, int W, int days){
        int d = 1;
        
        int temp = 0;
        
        for(int i = 0 ;i < weights.size() ; i++){
            
            temp += weights[i];
            
            if(temp > W){
                
                temp = 0;
                d++;
                i--;
            }
            
            if(d > days){
                return false;
            }
        }
        
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int l = -1, r = 0;
        for(auto & x : weights){
            l = max(l, x);
            r += x;
        }
        cout << "l = " << l << endl;
        cout << "r = " << r << endl;
        
        int ans = 0;
        
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(check(weights, mid, days)){
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