class Solution {
public:
    bool isValid(vector<int> w, int ourWeight, int days){
        int d = 1;
        int sum = 0;
        
        for(int i = 0 ; i <w.size() ; i++){
            sum+=w[i];
            if(sum > ourWeight){
                d++;
                sum = w[i];
            }
            if(d > days){
                return false;
            }
        }
        
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        int start = *max_element(weights.begin(), weights.end());
        int end = accumulate(weights.begin(), weights.end(), 0);
        int res = -1;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            
            if(isValid(weights, mid, days) == true){
                // go left;
                res = mid;
                end = mid-1;
            }
            else{
                start = mid +1;
            }
        }
        
        return res;
                             
        
    }
};