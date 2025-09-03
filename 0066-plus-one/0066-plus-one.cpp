class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int incr = 1;
        int i = digits.size() - 1;
        while (incr == 1 && i >= 0){
            digits[i]++;
            digits[i] %= 10;
            if(i == 0 && digits[i] == 0){
                digits.emplace(digits.begin(),1);
                break;
            }
            if(digits[i] == 0){
                incr = 1;
                i--;
            }
            else{
                incr = 0;
            }
            
        }
            
            
        return digits;
    }

};