class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }
        vector<int> v(128,0);
        for(auto i:t){
            v[i]++;
        }
        int l = 0, r = 0, count = t.size(), min_len = INT_MAX, startIndex = 0;
        while(r<s.size()){
            if(v[s[r++]]-- >0) count--;
            while(count == 0){
                if(r - l<min_len){
                    min_len = r-l;
                    startIndex = l;
                }
                if(v[s[l++]]++ == 0){
                    count++;
                }
            }
        }
        return min_len == INT_MAX ? "" : s.substr(startIndex, min_len);
    }
};