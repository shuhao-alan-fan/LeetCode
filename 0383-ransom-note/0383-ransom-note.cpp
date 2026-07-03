class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> map;
        for(char c : magazine){
            map[c]++;
        }
        for(char c:ransomNote){
            if(map.find(c) == map.end()) return false;
            map[c]--;
        }
        for(const auto & [c,i] : map){
            if(i<0) return false;
        }
        return true;
    }
};