class Solution {
public:
    bool isPalindrome(int x) {
        string word = to_string(x);
        int left = 0, right = word.size() - 1;
        while(left <= right){
            if(word[left] != word[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};