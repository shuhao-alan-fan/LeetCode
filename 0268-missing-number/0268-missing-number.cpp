class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = (1+n)*n / 2;
        int sum = 0;
        for(int i:nums){
            sum+=i;
        }
        return total - sum;
    }
};