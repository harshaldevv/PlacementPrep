class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // deque
        // storing / maintain in decreasing fashion
        int  n = nums.size();
        
        vector<int> ans;
        
        deque<int> q;
        
        for(int i = 0 ; i < n ; i++){
            
            // As the window move on, element nums[i-k] will be outdated.
            while(!q.empty() && q.front() == i - k){
                q.pop_front();
            }
            
            // now we've got/ maintained our queue of size k 
            
            
            // Now we are ready to push our new element nums[i]'s index into the queue.
           // But before that, we should clear elements which is smaller then nums[i].
           // Why? Because if nums[i] is bigger then nums[i], 
           // there will be no way for nums[i] be selected as the max number in range (i-k, i]
            
            while(!q.empty() && nums[q.back()] <= nums[i]){
                q.pop_back();
            }
            
             // Now push the index into our queue.
            q.push_back(i);
            
            // Okay, now nums[queue.front()] mush be the max number in range (i-k+1, i] 

            if( i >= k-1 ){
                ans.push_back(nums[q.front()]);
            }
        }
        
        return ans;
    }
};