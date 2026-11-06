class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size() - 2; i++){
            int left = i + 1, right = nums.size() - 1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum < 0) left++;
                else if(sum > 0) right--;
                else if(sum == 0){
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while(left<nums.size()-1 && nums[left] == nums[left+1]) left++;
                    while(right>0 && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                }
            }
            while(i < nums.size() - 2 && nums[i+1] == nums[i]) i++;
        }
        return ans;
    }
};