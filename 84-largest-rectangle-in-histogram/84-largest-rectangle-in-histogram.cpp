class Solution {
public:
    vector<int> NSR(vector<int> &arr){
        stack<pair<int, int>> st;
        vector<int> v;
        int pseudoIndex = arr.size() ;
        
        for(int i = arr.size() -1 ; i >=0  ; i--){
            if(st.size() == 0){
                v.push_back(pseudoIndex);
            }
            
            if(st.size() > 0 && st.top().first < arr[i]){
                v.push_back(st.top().second);
            }
            if(st.size() > 0 && st.top().first >= arr[i]){
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
        
        // for(int i = 0 ; i < arr.size() ; i++){
        //     v[i] = i- v[i];
        // }
        
        reverse(v.begin(), v.end());
        return v;
    }
    
    vector<int> NSL(vector<int> &arr){
        stack<pair<int, int>> st;
        vector<int> v;
        int pseudoIndex = -1;
        
        for(int i = 0 ; i < arr.size() ; i++){
            if(st.size() == 0){
                v.push_back(pseudoIndex);
            }
            
            if(st.size() > 0 && st.top().first < arr[i]){
                v.push_back(st.top().second);
            }
            if(st.size() > 0 && st.top().first >= arr[i]){
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
        
        // for(int i = 0 ; i < arr.size() ; i++){
        //     v[i] = i- v[i];
        // }
        
        return v;
    }
    
    
    int largestRectangleArea(vector<int>& heights) {
        // find NSR index
        vector<int> right = NSR(heights);
        
        for(int i = 0 ; i < right.size() ; i++){
            cout << right[i] << " " ;
        }
        // find NSL index
        vector<int> left = NSL(heights);
        cout << endl;
        for(int i = 0 ; i < left.size() ; i++){
            cout << left[i] << " " ;
        }
        
        int maxArea = -1;
        
        // find width[] --> right - left -1
        vector<int> width(heights.size(), -1);
        vector<int> area(heights.size(), -1);
        
        for(int i = 0 ; i < heights.size() ; i++){
            width[i] = right[i] - left[i] -1;
            area[i] = width[i] * heights[i];
            maxArea = max(area[i], maxArea);
        }
        // find area array
        
        // return maximum in area array
        
        return maxArea;
    }
};