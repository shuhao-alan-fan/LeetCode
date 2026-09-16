class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> ans;
        for(int j : nums2){
            if(s.count(j)){
                ans.push_back(j);
                s.erase(j);
            }
        }
        return ans;
    }
};