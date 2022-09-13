class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        // k suggest usage of heap
        
        // closest now means -> what to use -> min/max ?
        
        // closest means diff should be as low as possible
        // therefore if we keep getting elements with max diff --> ie max heap
        
        // and then end we'll have elements with the least possible diff, cuz 
        
        // humne pehle hi max diff wale uda denge
        
        
        priority_queue<pair<int, int>> maxH;
        vector<int> ans;
        
        for(auto &p : arr){
            int diff = abs(p-x);
            maxH.push({diff, p});
            
            if(maxH.size() > k){
                maxH.pop();
            }
        }
        
        while(!maxH.empty()){
            auto topp = maxH.top();
            ans.push_back(topp.second);
            maxH.pop();
        }
        
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};