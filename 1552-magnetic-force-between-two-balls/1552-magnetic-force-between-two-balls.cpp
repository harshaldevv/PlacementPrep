class Solution {
public:
    bool isValid(vector<int> &pos, int magnets, int myDist){
        // magnets --> total magnets i have
        
        int m = 1;
        int start = pos[0];
        for(int i = 1 ; i < pos.size() ; i++){
            if(pos[i] - start >= myDist){
                m++;
                start = pos[i];
            }
            
            if(m == magnets){
                return true;
            }
        }
        
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        int start = 1;
        int end = 1000000000;
        
        sort(position.begin(), position.end());
        
        long res = -1;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            if(isValid(position, m, mid) == true){
                res = mid;
                //find a larger dist
                start = mid +1;
            }
            else{
                end = mid-1;
            }
        }
        
        return res;
        
    }
};