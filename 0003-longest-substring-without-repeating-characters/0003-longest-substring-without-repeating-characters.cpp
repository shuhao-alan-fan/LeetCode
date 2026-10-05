class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> cnt;
        int max_len = 0;
        int l = 0;
        for(int r = 0; r<s.size(); r++){
            while(cnt.count(s[r])){
                cnt.erase(s[l++]);
            }
            cnt.insert(s[r]);
            max_len = max(max_len, r - l + 1);
        }
        return max_len;
    }
};