class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double sum;
        int prev = 0;
        for(auto b : brackets){
            int segment = b[0], rate = b[1];
            if(income <= prev) break;
            if(segment > income) sum+= (double)(income - prev)*rate * 0.01;
            else sum+= (double)(segment - prev)*rate * 0.01;
            prev = segment;
        }
        return sum;
    }
};