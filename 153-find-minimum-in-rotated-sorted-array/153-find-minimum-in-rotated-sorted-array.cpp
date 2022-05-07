class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        
        int start = 0;
        int end = n-1;
        
        if(nums[start] <= nums[end]){
            return nums[start]; // array already sorted;
        }
        
        
        
        // int pivotIndex = getPivot(nums);
        
        //finding pivot
        while(start <= end){
            
            int mid = start + (end-start)/2;
            cout << "mid = " << mid << endl;
            int next = (mid+1)%n;
            int prev = (mid-1+n)%n;
            
            if(nums[mid] <= nums[prev]  && nums[mid] <= nums[next]){
                //found pivot   
                return nums[mid];
            }
            
            else if(nums[end] <= nums[mid]){
                // this part is sorted, 
                // FIND in the other unsorted part
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        
        
        return -5001;
        
        
    }
};