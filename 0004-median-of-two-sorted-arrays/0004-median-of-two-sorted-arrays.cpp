class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        if(n2 < n1){
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int l = 0;
        int r = n1;
        int len = n1 + n2 ;
        
        while(l<=r){
            int mid = l + (r-l)/2;
            
            int cut1 = mid;
            int cut2 = (len+1)/2 - cut1;
            
            int l1 = cut1 - 1 >= 0 ?  nums1[cut1-1]  : INT_MIN;
            int l2 = cut2 - 1 >= 0 ? nums2[cut2-1] : INT_MIN;
            int r1 = cut1 < n1 ? nums1[cut1] : INT_MAX;
            int r2 = cut2 < n2 ? nums2[cut2] : INT_MAX;
            
            if(l1 <= r2 && l2 <= r1){
                if( (len+1)%2 == 0 ){
                    // odd;
                    return max(l1, l2);
                }
                else{
                    return ( max(l1, l2) + min(r1, r2) )/ 2.0 ;
                }
            }
            else if(l1  > r2){
                // go left
                r = mid-1;
            }
            else{
                l = mid +1;
            }
        }
        
        return -1;
        
    }
};