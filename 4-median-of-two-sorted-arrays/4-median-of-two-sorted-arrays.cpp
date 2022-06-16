class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        if(n1 > n2){
            return findMedianSortedArrays(nums2, nums1);
        }
        
        //solving this ques assuming nums1 size (n1) < nums2 size (n2)
           
        int length = n1+n2;
    
        int start = 0;
        int end = n1 ;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            
            int cut1 = mid;
            int cut2 = (length +1 )/2 - cut1; 
            // (n1+ n2 +1)/2 - cut1 --> works for both odd and even length(n1+n2)
            
            int l1 = cut1 == 0  ? INT_MIN : nums1[cut1-1];
            int l2 = cut2 == 0  ? INT_MIN : nums2[cut2-1];
            
            int r1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int r2 = cut2 == n2 ? INT_MAX : nums2[cut2];
                        
            if(l1 <= r2 && l2 <= r1){
                //valid cut
                if((n1+n2)%2 != 0){
                    //odd length
                    return max(l1, l2);
                }
                else{
                    // even length 
                    return (max(l1, l2) + min(r1, r2))/2.0;
                }
            }
            else if(l1 >r2){
                end = mid -1;
            }
            else{
                start = mid +1;
            }
        }
        
        return 0.0;
        
        
        
        
    }
};