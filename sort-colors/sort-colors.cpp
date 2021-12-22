class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        // both my approaches are 2 pointer approach and are the same. Initally it didnt strike me that the commented approach is called 2 pointer approach
        
        int low = 0; // start
        int high = nums.size() -1; // end
        
        for (int i = low; i <= high;){
            if(nums[i] == 0){
                swap(nums[low], nums[i]);
                i++;
                low++;
            }
            else if ( nums[i] == 1){
                i++;
            }
            else{
                // nums[i] == 2;
                swap(nums[high], nums[i]);
                high--;
            }
            
        }
        
        
        
// reference video - https://www.youtube.com/watch?v=oaVa-9wmpns&ab_channel=takeUforward 
// 	int low = 0;
// 	int mid = 0;
// 	int high = nums.size() -1;

// 	while ( mid <= high){
// 		if(nums[mid] == 0){
// 			//swap nums[low] and nums[mid]
// 			swap(nums[low], nums[mid]);
// 			low++;
// 			mid++;
// 		}
// 		else if ( nums[mid] == 1){
// 			mid++;


// 		}
// 		else{
// 			// ie -->  nums[mid] == 2
// 			swap(nums[mid], nums[high]);
// 			high--;

// 		}
// 	}
        
    }
};