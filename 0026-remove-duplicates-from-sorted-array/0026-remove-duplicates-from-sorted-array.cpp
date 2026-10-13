class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        int n = nums[0];
        for(int i = 1; i<nums.size(); i++){
            while(i<nums.size() && nums[i] == n){
                i++;
            }
            if(i<nums.size()){
                n = nums[i];
                nums[k] = n;
                k++;
            }
            else{
                return k;
            }
        }
        return k;
    }
};