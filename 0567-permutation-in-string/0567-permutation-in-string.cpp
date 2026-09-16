class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<int,int> cnt1;
        unordered_map<int,int> cnt2;
        int n = s1.size();
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
            if(cnt2[out] == 0) cnt2.erase(out);
            if(cnt1 == cnt2) return true;
        }
        return false;
    }
};