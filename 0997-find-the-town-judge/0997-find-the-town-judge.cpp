class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //hci research
        
        
        vector<int> indegree(n + 1), outdegree(n + 1);
        for (auto& t : trust) {
            outdegree[t[0]]++;
            indegree[t[1]]++;
        }
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == n - 1 && outdegree[i] == 0) {
                return i;
            }
        }
        return -1;
        
    }
};