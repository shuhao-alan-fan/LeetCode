class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0] >= target ? 1 : 0;
        int left = 0, mid = 0;
        int res = INT_MAX;
        vector<int> group(n+1,0);
        
        for(int i = 0; i<n; i++){
            group[i+1] = nums[i] + group[i];
        }
        for(int i = 0; i<n; i++){
            int new_target = target + group[i];
            int l = i+1, r = n;
            int m = l + (r-l)/2;
            while(l<r){
                m = l + (r-l)/2;
                if(group[m] >= new_target){
                    r = m;
                }
                else if (group[m] < new_target){
                    l = m+1;
                }
            }
            if(group[l] >= new_target){
                res = min(res, l-i);
            }
            
            
        }
        
        return res == INT_MAX ? 0: res;
    }
};