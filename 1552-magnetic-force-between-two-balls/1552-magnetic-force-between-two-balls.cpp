class Solution {
public:
    int isvalid(int F, vector<int> &pos, int m){
        int balls = 1;
        int latest = 0;
        
        for(int i = 1 ; i < pos.size(); i++){
            if(abs(pos[i] - pos[latest]) >= F){
                
                latest = i;
                
                balls++;
                
                if(balls == m){
                
                    return true;
                }
            }
        }
        
        
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        int start = 1;
        int end = 1000000000;
        
        int res = -1;
        sort(position.begin(), position.end());
        while(start <= end){
            int mid = start + (end-start)/2;
            cout << endl;
            
            if(isvalid(mid, position, m)){
                res = mid;
                start = mid+1;
                
            }
            else{
               end = mid -1;
            }
        }
        
        return res;
    }
};