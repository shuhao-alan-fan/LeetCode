class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> nums1,nums2;
        for(int i = 1; i<n;i++){
            nums1.push_back(nums[i]);
        }
        nums2 = nums;
        nums2.pop_back();
        return max(helper(nums1), helper(nums2));
    }
    int helper(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n+1,0);
        dp[1] = nums[0];
        for(int i = 1; i<n; i++){
            dp[i+1] = max(dp[i],dp[i-1]+nums[i]);
        }
        return dp[n];
    }
};