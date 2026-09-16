class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        array<int,26> cnt1{}, cnt2{};
        int n = s1.size(), m = s2.size();
        if(n > s2.size()) return false;
        for(int i = 0; i<n; i++){
            cnt1[s1[i] - 'a']++;
            cnt2[s2[i] - 'a']++;
        }
        if(cnt1 == cnt2) return true;
        for(int i = n; i<s2.size(); i++){
            int in = s2[i] - 'a';
            int out = s2[i-n] - 'a';
            cnt2[in] ++;
            cnt2[out]--;
            if(cnt1 == cnt2) return true;
        }
        return false;
    }
};