class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        return dfs(dp,triangle,0,0);

    }
    int dfs(vector<vector<int>>& dp,vector<vector<int>>& triangle, int r, int c){
        if(r >= triangle.size()){
            return 0;
        }
        if(dp[r][c] != INT_MAX){
            return dp[r][c];
        }
        int down = dfs(dp,triangle,r+1,c);
        int right = dfs(dp,triangle, r+1,c+1);
        return dp[r][c] = triangle[r][c] + min(down, right);
    }
};