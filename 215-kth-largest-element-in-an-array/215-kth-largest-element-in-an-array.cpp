class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        // Kth element or "Largest" --> either of them suugest "HEAP"
        // after heap is decided, which heap(min/max) to use
        // thererfore "Largest" --> "MIN" Heap is to be used
        
        
        priority_queue<int, vector<int>, greater<int>> minh;
        
        for(auto x : nums){
            minh.push(x);
            if(minh.size() > k){
                minh.pop();
            }
        }
        
        return minh.top();
        
    }
};