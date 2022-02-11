class Solution {
public:
    
    vector<int> NSR(vector<int> arr, int n){
        stack<pair<int, int> > st;
        vector<int> v;
        
        int pseudoIndex = n;  //  --> n == size of the array
        
        for(int i = n-1; i>=0 ; i--){
            if(st.size() == 0){
                v.push_back(pseudoIndex);
            }
            
            if(st.size() > 0 && st.top().first < arr[i]){
                v.push_back(st.top().second);
            }
            if(st.size() >0 && st.top().first >= arr[i]){
                while(st.size() >0 && st.top().first >= arr[i]){
                    st.pop();
                }
                
                if(st.size() == 0){
                    v.push_back(pseudoIndex);
                }
                else{
                    v.push_back(st.top().second);
                }
            }
            
            st.push({arr[i], i});
        }
        
        reverse(v.begin(), v.end());
        return v;
    }
    
    vector<int> NSL(vector<int> arr, int n){
        stack<pair<int, int> > st;
        vector<int> v;
        
        int pseudoIndex = -1;  //  --> n == size of the array
        
        for(int i = 0; i<n ; i++){
            if(st.size() == 0){
                v.push_back(pseudoIndex);
            }
            
            if(st.size() > 0 && st.top().first < arr[i]){
                v.push_back(st.top().second);
            }
            if(st.size() >0 && st.top().first >= arr[i]){
                while(st.size() >0 && st.top().first >= arr[i]){
                    st.pop();
                }
                
                if(st.size() == 0){
                    v.push_back(pseudoIndex);
                }
                else{
                    v.push_back(st.top().second);
                }
            }
            
            st.push({arr[i], i});
        }
        
        return v;
    }
    
    int MAH(vector<int> arr){
        //arr[] = heights ki array
        int size = arr.size();
        vector<int> right = NSR(arr, size);
        vector<int> left = NSL(arr, size);
        
        vector<int> width(size, -1);
        vector<int> area(size, -1);
        int maxArea = -1;
        for(int i = 0 ; i < size ;i++){
            width[i] = right[i] - left[i] -1;
            area[i] = width[i] * arr[i];
            maxArea = max(area[i], maxArea);
        }
        
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int col = matrix[0].size();
        
        vector<int> v;
        
        //copying the first row of the matrix
        for(int j = 0 ; j < col ; j++ ){  
            // v.push_back(matrix[0][j]);
            
            if(matrix[0][j] == '0'){
                v.push_back(0);
            }
            else{
                v.push_back(1);
            }
            
        }
        
        int answer = MAH(v);
        cout << "ans = " << answer << endl;
        
        
        
        for(int i = 1; i < rows ; i++){
            for(int j = 0 ; j < col ; j++){
                if(matrix[i][j] == '0'){
                    v[j] = 0;
                }else{
                    v[j] =  v[j] + 1 ;
                    // v[j] = v[j] + matrix[i][j]; // matrix[i][j] = 1 hoga ab
                    
                }   
            }
            answer = max(MAH(v), answer);
            cout << "ans = " << answer << endl;
        }
        
        return answer;
        
    }
};