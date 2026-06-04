class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1) return 0;
        int i  = 1;
        int buy = prices[0];
        int sell = prices[1];
        int ans = sell - buy;
        while(i<prices.size() - 1){
            if(prices[i] < buy){
                buy = prices[i];
                sell = prices[i+1];
            }
            else{
                sell = max(prices[i+1],sell);
            }
            ans = max(ans, sell-buy);
            i++;
        }
        return max(0,ans);
    }
};