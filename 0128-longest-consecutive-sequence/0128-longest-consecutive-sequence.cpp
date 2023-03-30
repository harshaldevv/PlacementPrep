#include <unordered_set>
#include <vector>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        
        //hci research
        std::unordered_set<int> numSet;
        for (const int& num : nums) {
            numSet.insert(num);
        }
        
        int longestStreak = 0;
        for (const int& num : nums) {
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }
                longestStreak = std::max(longestStreak, currentStreak);
            }
        }
        
        return longestStreak;
    }
};
