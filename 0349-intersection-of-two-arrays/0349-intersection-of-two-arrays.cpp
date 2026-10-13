class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> s;
        unordered_set<int> seen;
        for(int i:nums1){
            s.insert(i);
        }
        for(int i:nums2){
            if(s.count(i) && !seen.count(i)) res.push_back(i);
            seen.insert(i);
        }
        return res;

    }
};