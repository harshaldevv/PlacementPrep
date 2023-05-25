class Solution {
public:
    vector<int> farthestGreatestLeft(vector<int> &nums){
        int n = nums.size();
        
        vector<int> v(n);
        
        v[0] = nums[0];
        
        for(int i = 1 ; i < n ; i++){
             v[i] = max(v[i-1], nums[i]);
        }
        
        return v;
    }
    
    vector<int> farthestGreatestRight(vector<int> &nums){
        int n = nums.size();
        
        vector<int> v(n);
        
        v[n-1] = nums[n-1];
        
        for(int i = n-2 ; i >=0  ; i--){
             v[i] = max(v[i+1], nums[i]);
        }
        
        return v;
    }
    int trap(vector<int>& height) {
        
        vector<int> left = farthestGreatestLeft(height);
        vector<int> right = farthestGreatestRight(height);
        int n = height.size();
        
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            int h = min(left[i], right[i]);
            int w = h-height[i];
            ans += w;
        }
        
        return ans;
        
    }
};