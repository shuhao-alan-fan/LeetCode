class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double sum;
        int prev = 0;
        for(auto b : brackets){
            int segment = b[0], rate = b[1];
            int taxable = min(income, segment) - prev;
            if(taxable <= 0) break;
            sum+= (double)taxable *rate * 0.01;
            prev = segment;
        }
        return sum;
    }
};