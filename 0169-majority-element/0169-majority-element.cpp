class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 1, candidate = nums[0];
        for(int i = 1; i<nums.size(); i++){
            if(freq == 0) candidate = nums[i];
            if(nums[i] == candidate) freq++;
            else freq--;
        }
        return candidate;
    }
};