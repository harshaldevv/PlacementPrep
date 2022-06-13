class Solution {
public:
    
    int isvalid(vector<int> &weights, int D, int capacity){
        int days = 1;
        int sum = 0;
        
        for(int i = 0 ; i < weights.size() ; i++){
            sum+=weights[i];
            if(sum > capacity){
                days++;
                sum = weights[i];
            }
            if(days > D){
                return false;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int start = *max_element(weights.begin(), weights.end()); 
        // ye isliye karna hai 
        // kyuki agar yahan se start nahi kia humne ship ki capacity, 
        // toh iska matlab if ship capacity <  wt of heaviest box,
        // toh woh box kabhi jaa hi nahi payega ship se
        
        // if(weights.size() < days){
        //     return 
        // }
        
        int end =  500*5*10000; //accumulate(weights.begin(), weights.end());
        int res = -1;
        while(start <= end){
            int mid = start + (end-start)/2;
            
            if(isvalid(weights, days, mid)){
                res = mid;
                end = mid -1;
            }
            else{
                start = mid +1;
            }
        }
        
        return res;
                             
                             
        
    }
};