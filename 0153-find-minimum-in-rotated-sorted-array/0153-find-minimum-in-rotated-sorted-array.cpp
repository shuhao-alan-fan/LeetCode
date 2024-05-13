class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()<2) return nums[0];
        int l = 0, r = nums.size() - 1;
        
        int min_n = INT_MAX;
        while(l<=r){
            int m = (l+r)/2;
            if(r == l+1){
                return min(nums[l],nums[r]);
            }
            if(nums[m]<nums[m-1]){
                return nums[m];
            }
            else{
                if(nums[m]>nums[r]){
                    l = m;
                }
                else{
                    r = m;
                }
            }
        }
        
        return -1;

    
    }
};