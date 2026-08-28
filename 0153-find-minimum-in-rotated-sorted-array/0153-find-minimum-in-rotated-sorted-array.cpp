class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int ans = INT_MAX;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < nums[left]){
                right = mid - 1;
                ans = min(nums[mid], ans);
            }
            else if (nums[mid] >= nums[right]){
                left = mid + 1;
                ans = min(nums[right],ans);
            }
            else{
                ans = min(nums[left],ans);
                return ans;
            }
        }
        return ans;
    }
};