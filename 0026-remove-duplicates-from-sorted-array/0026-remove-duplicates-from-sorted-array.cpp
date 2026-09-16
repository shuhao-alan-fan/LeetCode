class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size() == 0) return 0;
        int k = 1;
        
        for(int j = 1; j<nums.size(); j++){
            if(nums[j] != nums[k-1]){
                nums[k++] = nums[j];
            }
        }
        return k;
    }
};