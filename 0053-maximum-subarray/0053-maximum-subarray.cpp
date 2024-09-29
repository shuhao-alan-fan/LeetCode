#include <vector>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = 0, max_i = INT_MIN;
        int sum = 0;
        for(int i : nums){
            max_i = max(i,max_i);
            sum+=i;
            if(sum < 0) sum = 0;
            max_sum = max(max_sum, sum);
        }
        if(max_sum == 0) return min(max_i, max_sum);
        else return max_sum;
    }
};