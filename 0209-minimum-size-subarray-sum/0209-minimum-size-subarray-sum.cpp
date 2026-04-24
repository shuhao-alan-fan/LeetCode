class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0] >= target ? 1 : 0;
        int left = 0, mid = 0;
        int res = INT_MAX;
        int prefix_sum = 0;
        int total = 0;
        vector<int> group;
        
        for(int i:nums){
            total+=i;
            group.push_back(total);
        }
        for(int i = 0; i<n; i++){
            if(group[i] < target) continue;
            else{
                res = min(res,i+1);
                for(int j = 0; j<i; j++){
                    if(group[i] - group[j] >= target){
                       res = min(res, i-j);
                    }
                }
            }
            
        }
        
        return res == INT_MAX ? 0: res;
    }
};