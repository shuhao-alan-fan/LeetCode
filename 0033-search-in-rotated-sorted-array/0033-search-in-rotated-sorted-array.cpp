class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        int p = 0; //pivot
        while(l<r){
            int m = l + (r - l)/2;//integer overflow
            
            if(nums[m] > nums[r]){
                l = m + 1;
            }
            else{
                r = m;
            }
        }
        p = l;
        l = 0, r = nums.size()-1;
        if(target >= nums[p] && target <= nums[r]){
            l = p, r = nums.size() - 1;
            
            
        }else{
            l = 0, r = p;
        }
        while(l <= r){
                int m = l + (r - l)/2;
                if(target == nums[m]){
                    return m;
                }
                if(target < nums[m]){
                    r = m - 1;
                }
                else{
                    l = m+1;
                }
            }
        
        return -1;
        
    }
};