class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right-left) / 2;
            if(nums[left] <= nums[right]) return nums[left];
            if(nums[left] <= nums[mid] && nums[mid] >= nums[right]){
                left = mid  + 1;
            }
            else{
                right = mid;
            }
            if(nums[mid] <= nums[right] && nums[mid] <= nums[left]){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return nums[0];
    }
};