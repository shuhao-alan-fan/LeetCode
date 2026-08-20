class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int count1[26], count2[26];
        
        for(int i=0; i<s.size(); i++){
            count1[s[i]-'a']++;
            count2[t[i]-'a']++;
        }
        
        for(int i =0; i<26; i++){
            if(count1[i] != count2[i]) return false;
        }
        return true;
    }
};