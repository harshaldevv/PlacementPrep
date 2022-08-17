class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        
        int rows = image.size();
        int cols = image[0].size();
        
        for(int i = 0 ; i < rows; i++){
            
            int l = 0;
            int r = cols-1;
            
            while(l<=r){
                swap(image[i][l++], image[i][r--]);
            }
            
            for(int j = 0 ; j < cols ; j++){
                image[i][j] = !image[i][j];
            }
        }
        
        return image;
        
        
        
    }
};