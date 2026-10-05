class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        vector<int> ans;
        while(left <= right){
            int l;
            if(abs(nums[right]) >= abs(nums[left])){
                l = nums[right] * nums[right];
                right--;
            }
            else {
                l = nums[left] * nums[left];
                left++;
            }
            ans.push_back(l);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};