class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(), carry = 0;
        for(int i = n-1; i>=0; i--){
            if(digits[i] < 9){
                digits[i]++;
                return digits;
            }
            else{
                digits[i] = 0;
                carry = 1;
            }
        }
        if(carry){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};