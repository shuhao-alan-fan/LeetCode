class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        int empty = numBottles;
        while(empty >= numExchange){
            empty -= numExchange;
            ans ++;
            empty += 1;
            numExchange += 1;
        }
        return ans;
    }
};