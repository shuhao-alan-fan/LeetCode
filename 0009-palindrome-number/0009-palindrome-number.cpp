class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long x_copy = (long long)x;
        long long temp = 0;
        while(x > 0){
            int i = x % 10;
            x/=10;
            temp *= 10;
            temp += i;
            
        }
        return temp == x_copy;
    }
};