class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0) return "";
        if(s.size() == 1) return s;
        int len = INT_MIN, startIndex = 0;
        int count = 0;

        for(int i = 0; i<s.size() * 2 -1; i++){
            int l = i/2, r = (i+1)/2;
            while(l>=0 && r<s.size() && s[l] == s[r]){
                count = r - l + 1;
                if(count > len){
                    len = count;
                    startIndex = l;
                }
                l--;
                r++;
            }
            
        }
        return len == INT_MIN ? "" : s.substr(startIndex,len);
    }
};