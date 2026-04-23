class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,vector<int>> map;
        unordered_map<int,long long> prefix_sum;
        int n = nums.size();
        vector<long long> ans(n,0);
        for(int i = 0; i<n; i++){
            map[nums[i]].push_back(i);
        }

        for(auto indices:map){
            long long prefix_sum = 0;
            auto group = indices.second;
            long long total = accumulate(group.begin(), group.end(), 0LL);

            for(long long i = 0; i<group.size(); i++){
                
                long long leftsum = i*group[i] - prefix_sum;
                long long rightsum = total - prefix_sum - (group.size()-i)*group[i];
                ans[group[i]] = leftsum+rightsum;
                prefix_sum += group[i];
            }
            
        }

        return ans;
    }
};