class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> v(n+1);
        vector<int> ans;
        unordered_map<int,int> map;
        for(int i : nums){
            map[i]++;
        }
        for(const auto& [number,freq]: map){
            v[freq].push_back(number);
        }
        
        for(int i = v.size()-1; i >= 0 && k>0; i--){
              
            if(v[i].empty()) continue;
            for(int j = 0; j<v[i].size(); j++){
                if(k == 0) break;
                ans.push_back(v[i][j]);
                k--;
            }
            
        }
        
        return ans;
    }
};