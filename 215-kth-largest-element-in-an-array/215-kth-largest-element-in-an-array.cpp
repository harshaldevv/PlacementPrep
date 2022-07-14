class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        // redo 
        
        // kth largeest ->>> min heap
        priority_queue<int, vector<int>, greater<int>> pq; // minheap
        
        for(auto x : nums){
            pq.push(x);
            if(pq.size() > k){
                pq.pop();
            }
        }
        cout <<"done ---" << endl;
        
        return pq.top();
        
        
        // trivial soln --> Sort the array and return nums[k-1] 
        // TC - O(nlogn) , SC - O(1)
        
        
        // Kth element or "Largest" --> either of them suugest "HEAP"
        // after heap is decided, which heap(min/max) to use
        // thererfore "Largest" --> "MIN" Heap is to be used
        
        // TC - O(nlogk), SC - O(k)
        
//         priority_queue<int, vector<int>, greater<int>> minh;
        
//         for(auto x : nums){
//             minh.push(x);
//             if(minh.size() > k){
//                 minh.pop();
//             }
//         }
        
//         return minh.top();
        
    }
};