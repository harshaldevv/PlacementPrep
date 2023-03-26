class Solution {
public:
    bool check(int &mid, vector<int> &nums, int &m, int &k){
        int bouq = 0; // total no of bouqets we make 
        int f = 0; // flowers in our bouq so far
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] <= mid){
                f++;
            }
            else{
                f = 0; // reset counter -> kyuki we wanted 
                // K flowers together, ek saath,
                // jo ab hume nahi mile kyuki ek unbloomed flower aa gaya
                // hence reset kr dia counter
            }
            
            if(f == k){
                bouq++;
                f = 0;
            }
            if(bouq >= m){
                return true;
            }
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long l = 1;
        long long r = INT_MAX-100; // -100 kyuki integer overflow hua ek jagah xD
        int ans = -1;
        
        
        
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(check(mid, bloomDay, m, k)){
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