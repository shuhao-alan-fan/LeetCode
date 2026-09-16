class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> ms1, ms2;
        int len = s1.size();
        if(len > s2.size()) return false;
        for(char c : s1){
            ms1[c]++;
        }
        for(int i = 0; i<len; i++){
            ms2[s2[i]]++;
        }
        if(ms1 == ms2) return true;
        for(int i = len; i<s2.size(); i++){
            ms2[s2[i - len]]--;
            ms2[s2[i]]++;
            if(ms2[s2[i-len]] == 0){
                ms2.erase(s2[i-len]);
            }
            if(ms1 == ms2) return true;
        }
        return false;
    }
};