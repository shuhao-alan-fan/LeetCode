class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1) return 0;
        int ans = 0;
        int buy = prices[0];
        for(int i = 1; i<n; i++){
            int profit = prices[i] - buy;
            if(profit <= 0) buy = prices[i];
            if(profit > ans) ans = profit;
        }
        return ans;
    }
};