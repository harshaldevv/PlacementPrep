class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
        int rect1 = abs(ax2 - ax1) * abs(ay2-ay1);
        int rect2 = abs(bx2 - bx1) * abs(by2-by1);
        
        //check overlap
        
        if(bx1 >= ax2 || bx2 <= ax1 || ay2 <= by1 || ay1 >= by2){
            // no overlap
            return rect1+rect2;
        }
        
        //find overlap area
        int alpha = min(ay2, by2);
        int beta = max(ay1, by1);
        int gamma = max(bx1, ax1);
        int theta = min(bx2, ax2);
        
        int X = abs(beta - alpha);
        int Y = abs(gamma - theta);
        
        int overlapArea = X*Y;
        
        
        return rect1+rect2 - overlapArea;
        
        
        
    }
};



// 27 + 24 = 51 - 6
    
    
    