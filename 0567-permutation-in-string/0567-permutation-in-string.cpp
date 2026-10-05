class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<int,int> cnt1;
        unordered_map<int,int> cnt2;
        for(auto c: s1){
            cnt1[c - 'a']++;
        }
        int l = 0, n = s1.size(), m = s2.size();
        if(n > m) return false;
        for(int i = 0; i<n; i++){
            cnt2[s2[i]-'a']++;
        }
        if(cnt1 == cnt2) return true;

        for(int r = l + n; r<m; r++){
            cnt2[s2[r] - 'a']++;
            cnt2[s2[l] - 'a']--;
            if(cnt2[s2[l] - 'a'] == 0) cnt2.erase(s2[l] - 'a');
            l++;
            if(cnt1 == cnt2) return true;
        }
        return false;
        
    }
};