class Solution {
public:
    bool isValid(vector<int> &piles, int h, int probableRate){
        long long int hours = 0;
        for(int i = 0 ; i< piles.size() ; i++){
            hours += (piles[i]/probableRate);
            if(piles[i]%probableRate != 0){
                hours++;
            }
            if(hours > h){
            return false;
            }
        }

        return true;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        long start = 1; //start rate - 1 banana per hour
        long long int end = 1000000000; // end = all bananas per hour
        long k = -1;
        //cout << start << end << endl;
        while(start <= end){
            
            long mid = start + (end-start)/2;
            // mid == our probable k
        
            if(isValid(piles, h, mid)== true){
                k = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return k;
        
    }
};