class Solution {
public:
    int isvalid(int penalty, vector<int> &nums, int maxOps){
        int reqOps = 0;
        for(auto x : nums){
            int p = x / penalty;
            if(x%penalty == 0){
                p--;
            }
            reqOps += p;
            if(reqOps > maxOps){
                return false;
            }
        }
        
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int start = 1;
        int end = 1000000000;
        
        int res = end ; 
        
        while(start <= end){
            int mid = start + ( end-start)/2;
            
            if(isvalid(mid, nums, maxOperations)){
                res = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        
        return res;
        
    }
};