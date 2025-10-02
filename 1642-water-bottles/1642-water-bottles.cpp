class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty = numBottles;
        int ans = numBottles;
        while(empty >= numExchange){
            empty -= numExchange;
            empty++;
            ans++;
        }
        return ans;
    }
};