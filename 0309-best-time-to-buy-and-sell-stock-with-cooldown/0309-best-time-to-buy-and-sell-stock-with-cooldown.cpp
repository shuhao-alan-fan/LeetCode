class Solution {
public:

    int maxProfit(vector<int>& prices) {
        
        //0 for not buying and 1 for buying
        unordered_map<string,int> dp;
        return dfs(0,1,dp,prices);
    }

    int dfs(int day, int buying, unordered_map<string,int> &dp, vector<int>& prices){
        if(day >= prices.size()) return 0;
        if(dp.find(to_string(day) + to_string(buying)) != dp.end()){
            return dp[to_string(day) + to_string(buying)];
        }
        int cooldown = dfs(day+1, buying, dp, prices);
        if(buying == 1){
            dp[to_string(day)+to_string(buying)] = max(dfs(day+1,0,dp,prices) - prices[day],cooldown);
        }
        else{
            dp[to_string(day)+to_string(buying)] = max(dfs(day+2,1,dp,prices) + prices[day] ,cooldown);
        }
        return dp[to_string(day)+to_string(buying)];
    }
};