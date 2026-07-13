class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m != n) return false;
        unordered_map<char,char> map;
        unordered_set<char> set;
        for(int i = 0; i<m; i++){
            if(map.find(s[i]) == map.end()){
                if(set.find(t[i]) != set.end()) return false;
                map[s[i]] = t[i];
                set.insert(t[i]);
            }
            else if(map[s[i]] != t[i]) return false;
        }
        return true;
    }
};