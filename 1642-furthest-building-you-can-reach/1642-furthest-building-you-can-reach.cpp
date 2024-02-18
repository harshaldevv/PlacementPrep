class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        int i = 0 ;
        
        priority_queue<int> pq;
        for(; i < h.size() -1; i++ ){
            if(h[i] >= h[i+1] ){
                continue;
            }
            else{
                // now we need to jump using ladder or bricks
                
                
                int diff = abs(h[i] - h[i+1]);
                bricks -=diff;
                pq.push(diff);
                
                // if bricks become negetive then there were not enough bricks. 
                // So add a ladder in place of the step where most bricks were used
                if(bricks < 0){
                    // here use ladder
                    bricks += pq.top();
                    pq.pop();
                    
                    if(ladders > 0){
                        ladders--;
                    }
                    else{
                        return i;
                    }
                }
                
            }
        }
        
        return i;
        
    }
};