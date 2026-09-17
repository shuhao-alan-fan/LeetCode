class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),1);
        int fwd = 1, bwd = 1;
        for(int i = 0; i<nums.size(); i++){
            ans[i] = fwd * ans[i];
            fwd = fwd * nums[i];
        }
        for(int j = nums.size() - 1; j>= 0; j--){
            ans[j] = bwd * ans[j];
            bwd = bwd * nums[j];
        }
        return ans;
    }
};