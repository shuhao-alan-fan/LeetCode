class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        vector<int> ans;
        unordered_set<int> covered;
        for(int i:nums1){
            s.insert(i);
        }
        for(int j : nums2){
            if(s.count(j) && !covered.count(j)) {
                ans.push_back(j);
                covered.insert(j);
            }
        }
        return ans;
    }
};