
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // hci research
        
        
        // Create a hash table to store the frequency of each element in nums
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }
        
        // Create a min heap of size k to store the top k frequent elements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        // Loop through the hash table and add the top k frequent elements to the min heap
        for (auto entry : freqMap) {
            minHeap.push({entry.second, entry.first});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        // Create a vector to store the top k frequent elements
        vector<int> result(k);
        
        // Pop the top k frequent elements from the min heap and add them to the result vector
        for (int i = k - 1; i >= 0; i--) {
            result[i] = minHeap.top().second;
            minHeap.pop();
        }
        
        return result;
    }
};
