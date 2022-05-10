class Solution {
public:
    bool isValid(vector<int>& bloomDay, int m, int k, int days){
        int b = 0; // --> number of bouqets i can make 
        int d = 0;
        int flowersBloomed = 0;
        bool together = true;
        
        for(int i = 0 ; i < bloomDay.size() ; i++){
            if(bloomDay[i] <= days){
                flowersBloomed++;
                
                if(flowersBloomed == k){
                    b++;
                    flowersBloomed = 0;
                }
            }
            else{
                flowersBloomed = 0;
            }
        }
        
        if(b >= m){
            return true;
        }
        else{
            return false;
        }
        
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        if(m > (float)bloomDay.size()/k){
            return -1;
        }
        
        int start = 1;
        int end =  1000000000; //accumulate(bloomDay.begin(), bloomDay.end(), 0);
        
        int res = -1;
        
        while(start <= end){
            
            int mid = start + (end-start)/2;
            // mid signifies the number of days to blossom for the whole batch
            
            if(isValid(bloomDay, m, k , mid) == true){
                // go left
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