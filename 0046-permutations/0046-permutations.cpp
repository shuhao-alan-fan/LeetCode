class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        //added this check to make the runtime faster

        if (nums.size() == 0) {
            return {};
        }

        //implementation:

        vector<vector<int>> ans;
        dfs(0,nums, ans);
        return ans;
    }
    void dfs(int n, vector<int>& nums, vector<vector<int>>& ans){

        // check termination condition & append the current change

        if(n >= nums.size()){
            ans.push_back(nums);
            return;
        }
        
        //body of dfs, swap each two numbers for each n, all the way to the-
        //-whole num array

        for(int i = n; i<nums.size(); i++){
            swap(nums[n], nums[i]);
            dfs(n+1, nums, ans);
            swap(nums[n], nums[i]);
        }
        return;
    }
};