class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        //hci research
        
         int n = edges.size() + 1;
        vector<int> counts(n + 1, 0);
        for (auto& e : edges) {
            counts[e[0]]++;
            counts[e[1]]++;
        }
        for (int i = 1; i <= n; i++) {
            if (counts[i] == n - 1) {
                return i;
            }
        }
        return -1; // not found
        
    }
};