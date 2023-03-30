class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // hci research 
        
        
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adjList(numCourses);
        queue<int> q;
        int coursesTaken = 0;

        // Create adjacency list and calculate in-degrees
        for (auto pre : prerequisites) {
            adjList[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }

        // Add courses with zero in-degree to queue
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // Perform topological sort
        while (!q.empty()) {
            int currCourse = q.front();
            q.pop();
            coursesTaken++;

            for (auto neighbor : adjList[currCourse]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return coursesTaken == numCourses;
    }
};
