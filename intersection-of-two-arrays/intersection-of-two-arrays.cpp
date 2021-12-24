class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
    vector<int> ans;
	if(nums1.size() < nums2.size()){
		ans = helper(nums1, nums2);
	}
	else{
		ans = helper(nums2, nums1);
	}

	return ans;
}

vector <int> helper(vector<int> smaller, vector<int> larger){
	map<int, int> m;

	for(int i = 0; i < smaller.size(); i++){
		// m.insert(smaller[i], 1);
        m[smaller[i]] = 1;
	}

	vector<int> common;

	for(int i = 0 ; i < larger.size(); i++){
		if(m.count(larger[i]) > 0){
			common.push_back(larger[i]);
            m.erase(larger[i]);
		}
	}

	return common;
}

};