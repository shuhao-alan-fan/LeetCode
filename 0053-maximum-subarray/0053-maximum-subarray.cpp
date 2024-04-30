#include <vector>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //O（n) solution:
        int count = 0;
        int max_sum =  nums[0];
        for(auto i : nums){
            
           if(count < 0){
            count = 0;
           }
           
            count += i;
            max_sum = max(count, max_sum);
            
           
        }
        return max_sum;
    }
};