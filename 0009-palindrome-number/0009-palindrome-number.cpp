class Solution {
public:
    bool isPalindrome(int x) {
        //naive
        // string word = to_string(x);
        // int left = 0, right = word.size() - 1;
        // while(left <= right){
        //     if(word[left] != word[right]) return false;
        //     left++;
        //     right--;
        // }
        // return true;
        //without conversion
        if(x < 0) return false;
        long reverse = 0;
        int x_copy = x;
        while(x > 0){
            reverse = reverse * 10 + x%10;
            x /= 10;
        }
        return reverse == x_copy;

    }
};