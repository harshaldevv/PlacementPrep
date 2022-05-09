class Solution {
public:
    int lowerBS(vector<int> arr, int target){
        int n = arr.size();
        int start = 0;
        int end = arr.size() -1;
        int res = -1;
        while(start <= end){
            
            int mid = start + (end-start)/2;
            
            if(arr[mid] == target){
                res = mid;
                end = mid-1;
            }
            else if(arr[mid] > target){
                //go left
                end = mid-1;
            }
            else{
                // go right
                start = mid+1;
            }
        }
        
        return res;
        
    }
    
    int upperBS(vector<int> arr, int target){
        int n  = arr.size();
        int start = 0;
        int end = arr.size() -1;
        int res = -1;
        
        while(start<= end){
            int mid = start + (end-start)/2;
            
            if(arr[mid] == target){
                res = mid;
                start = mid +1;
            }
            else if(arr[mid] < target){
                // go right
                start = mid +1;
            }
            else{
                end = mid-1;
            }
        }
        
        return res;
        
    }
    
    
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        // first occurence index
        int first = lowerBS(nums, target);
        
        // last occurence index
        int last = upperBS(nums, target);
        
        vector<int> v;
        
        if(first == -1){ // target not in the array
            return v;
        }
        
        if(last != -1){ // single element
            for(int i = first ; i<= last ; i++){
            v.push_back(i);
            }
        }
        else{
            v.push_back(first);
        }
        
        
        return v;
    }
};