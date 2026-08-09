class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1) return 0;
        int ans = 0;
        for(int i = 0; i<prices.size() - 1; i++){
            int buy = prices[i];
            for(int j = i+1; j<prices.size(); j++){
                int sell = prices[j];
                if(buy >= sell){
                    i = j-1;
                    break;
                }
                ans = max(ans, sell - buy);
            }
        }
        return ans;
    }
};