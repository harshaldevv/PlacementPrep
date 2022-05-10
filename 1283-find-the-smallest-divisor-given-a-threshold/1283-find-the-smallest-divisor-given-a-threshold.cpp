class Solution {
public:
    bool isValid(vector<int> &nums, int divisor, int threshold){
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            sum+= (ceil((float)nums[i]/divisor));
            if(sum > threshold){
                return false;
            }
        }
        
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1;
        int end = 1000000;//accumulate(nums.begin(), nums.end(), 0);
        
        int res = -1;
        while(start <= end){
            
            int mid = start + (end-start)/2;
            // cout << "mid = " << mid << endl;
            
            if(isValid(nums, mid, threshold) == true){
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