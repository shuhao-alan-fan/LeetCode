class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x;
        long long revert = 0;
        while(temp > 0){
            revert*=10;
            revert += temp % 10;
            temp /= 10;
        }
        return revert == x;
    }
};