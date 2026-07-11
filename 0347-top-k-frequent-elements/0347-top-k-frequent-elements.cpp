class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>> v;
        vector<int> ans;
        unordered_map<int,int> map;
        for(int i : nums){
            map[i]++;
        }
        for(const auto& [number,freq]: map){
            v.push_back(make_pair(freq,number));
        }
        sort(v.begin(), v.end());
        for(int i = v.size()-1; k>0; k--){
            ans.push_back(v[i--].second);
        }
        return ans;
    }
};