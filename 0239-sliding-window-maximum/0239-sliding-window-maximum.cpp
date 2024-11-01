class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int max_ind;
        int l = 0, r = k - 1;
        int m = INT_MIN;
        for(int i = 0; i<k; i++){
            
            if(nums[i] >= m){
                m = nums[i];
                max_ind = i;
            }
        }
        res.push_back(m);
        for(int i = k; i<nums.size(); i++){

            if(max_ind == i - k){
                m = nums[i - k + 1];

                for(int j = i-k+1; j<i+1; j++){

                    if(nums[j] >= m){
                        m = nums[j];
                        max_ind = j;
                    }

                }
            }
            if(nums[i] >= m){
                m = nums[i];
                max_ind = i;
            }
             res.push_back(m);
        }
        return res;
    }
};