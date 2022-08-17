class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        
        int n = image.size();
        int rows = image.size();
        int cols = image[0].size();
        
        for(int r = 0 ; r < rows ; r++){
            reverse(image[r].begin(), image[r].end());
        }
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                image[i][j] = !image[i][j];
            }
        }
        
        return image;
    }
};