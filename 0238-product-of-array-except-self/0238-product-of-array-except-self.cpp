class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        int temp = 1;
        for(int i = 0; i<nums.size() - 1; i++){
            temp *= nums[i];
            ans[i+1] *= temp;
        }
        temp = 1;
        for(int i = nums.size() - 2; i>=0; i--){
            temp *= nums[i+1];
            ans[i] *= temp;
        }
        return ans;
    }
};