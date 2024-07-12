class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& candidates, int i, vector<int>& cur, int total, int target) {
        if(total == target){
            ans.push_back(cur);
            return;
        }
        if(i>=candidates.size() || total > target) return;

        cur.push_back(candidates[i]);
        dfs(candidates,i, cur, total + candidates[i], target);
        cur.pop_back();
        dfs(candidates, i+1, cur, total, target);
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp = {};
        dfs(candidates,0,temp,0,target);
        return ans;
    }
};
