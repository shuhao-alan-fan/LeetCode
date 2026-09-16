class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int n = s.size();
        int max_l = 0;
        int l = 0;
        for(int r = 0; r<n; r++){
            while(set.find(s[r]) != set.end()){
                set.erase(s[l]);
                l++;
            }
            set.insert(s[r]);
            max_l = max(max_l,r-l + 1);
            

        }
        return max_l;
    }
};