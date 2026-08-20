class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count1[26],count2[26];
        for(int i = 0; i<ransomNote.size(); i++){
            count1[ransomNote[i] - 'a']++;
        }
        for(int i = 0; i<magazine.size(); i++){
            count2[magazine[i] - 'a']++;
        }
        for(int i=0; i<26; i++){
            if(count1[i] > count2[i]) return false;
        }
        return true;
    }
};