class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        
        priority_queue<int> pq;
        
        //bricks are our limiting factor, as ladders can help us jump any height
        for(int i = 0 ; i < h.size()  -1 ; i++){
            
            if(h[i] > h[i+1]){
                continue;
            }
            else{
                // now we need to use bricks or ladder
                
                // use bricks
                
                int diff = abs(h[i] - h[i+1]);
                bricks-=diff;
                pq.push(diff);
                
                // if bricks become negetive then there were not enough bricks. 
                // So add a ladder in place of the step where most bricks were used
                if(bricks < 0){
                    bricks += pq.top();
                    pq.pop();
                    
                    ladders--;
                }
                
                if(ladders < 0){
                    return i;
                }
            }
        }
        
        return h.size() - 1; // we crossed the whole array
        
    }
};