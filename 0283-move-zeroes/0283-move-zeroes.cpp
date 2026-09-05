class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        queue<int> zeros;
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] == 0){
                zeros.push(i);
                continue;
            }
            else{
                if(!zeros.empty()){
                    int idx = zeros.front();
                    zeros.pop();
                    swap(nums[idx], nums[i]);
                    zeros.push(i);
                }
            }
        }
    }
};
