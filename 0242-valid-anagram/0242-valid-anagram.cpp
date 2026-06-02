class Solution {
public:
    bool isAnagram(string s, string t) {
        int count1[26] = {0};
        for(char c:s){
            count1[c - 'a']++;
        }
        int count2[26] = {0};
        for(char c:t){
            count2[c - 'a']++;
        }

        string key1;
        string key2;
        for(int i = 0; i<26; i++){
            key1 += to_string(count1[i]) + '#';
            key2 += to_string(count2[i]) + '#';
        }
        return key1 == key2;
    }
};