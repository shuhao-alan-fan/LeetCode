class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        array<int,128> lastSeen{};
        int l = 0,best = 0;
        for(int r = 0; r<s.size(); r++){
            l = max(l, lastSeen[s[r]]);
            best = max(best, r - l + 1);
            lastSeen[s[r]] = r+1;
        }
        return best;
    }
};