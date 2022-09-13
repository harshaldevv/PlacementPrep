class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        // trival soln --> sort karke answer nikal do --> Tc O(nlogn),   SC - O(1)
        
        
        // Optimized soln using heaps
        // kth largest --> means heaps ... and largest implies the use of "MIN" heap
        
        
        priority_queue<int, vector<int>, greater<int>> minH;
        
        for(auto &x : nums){
            minH.push(x);
            if(minH.size() > k){
                minH.pop();
            }
        }
        
        return minH.top();
        
    }
};