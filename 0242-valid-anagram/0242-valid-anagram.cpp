class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> map;
        for(char c : s){
            map[c]++;
        }
        for(char c:t){
            if(map.find(c) == map.end()){
                return false;
            }
            else{
                map[c]--;
            }
        }
        for(const auto& [c,i] : map){
            if(i!=0) return false;
        }
        return true;
    }
};