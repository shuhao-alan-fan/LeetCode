class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0; 
        for(int i:nums){
            sum+=i;
        }
        if(sum%2 != 0) return false;
        int target = sum / 2;
        vector<vector<bool>> dp(nums.size()+1, vector<bool>(sum+1,false));
        for(int i = 0; i< nums.size(); i++){
            dp[i][0] = true;
            dp[i][nums[i]] = true;
        }

        for(int i = 1; i< nums.size(); i++){
            for(int j = 1; j<=target; j++){
                if(j >= nums[i]){
                    dp[i][j] = dp[i-1][j - nums[i]] || dp[i - 1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[nums.size()-1][target];
    }
};