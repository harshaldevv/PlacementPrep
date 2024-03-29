class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        
        int gasSum = 0;
        int costSum = 0;
        
        for(int i = 0 ; i < n ; i++){
            gasSum += gas[i];
            costSum += cost[i];
        }
        
        if(gasSum < costSum){
            // soln doesnt exist
            return -1;
        }
        
        int start = 0; // index
        int tank = 0;
        
        
        for(int i = 0 ; i < n ; i++){
            
            tank += (gas[i] - cost[i]);
            
            if(tank < 0){
                start = i+1;
                tank = 0;
            }
        }
        
        return start;
        
        
        
        
        
    }
};