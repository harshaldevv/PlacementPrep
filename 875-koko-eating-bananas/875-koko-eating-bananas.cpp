class Solution {
public:
    long isvalid(int rate, vector<int> &piles, int h){
        long timeTaken = 0;
        
        for(auto x : piles){
            //cout << "x = " << x << endl; 
            long t = x/rate;
            //cout << "t = " << t << endl;
            
            if(x%rate != 0){ 
                //if the pile[i] has than 'k' bananas
                // k = rate 
                t++;
            }
            //cout << "t = " << t << endl;
            
            timeTaken += t;
            // cout << "timeTaken = " << timeTaken << endl;
            // cout << endl;
            
            if(timeTaken > h){
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // Binary search on answer
        // try on 14 Jun 2022
        
        int start =  1; //*max_element(piles.begin(), piles.end());
        int end = 0;
        end =  1000000000; //accumulate(piles.begin(), piles.end(), end);
        //cout << "end = " <<end << endl;
        
        long res = -1;
        while(start <= end){
            int mid = start+ (end-start)/2;
            //cout << "mid = " << mid << endl;
            if(isvalid(mid, piles, h)){
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