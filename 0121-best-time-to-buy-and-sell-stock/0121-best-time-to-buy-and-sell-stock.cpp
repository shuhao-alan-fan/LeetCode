class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b = 0, s = 1, max_prof = 0;
        while(s<prices.size()){
            max_prof = max(max_prof, prices[s] - prices[b]);
            if(prices[b] >  prices[s]) b = s;
            s++;

        }
        return max_prof;
    }
};