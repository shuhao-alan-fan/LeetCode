class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> map;
        unordered_set<string> set;
        vector<string> words;
        stringstream ss(s);
        string str;
        while(getline(ss,str,' ')){
            words.push_back(str);
        }
        if(words.size() != pattern.size()) return false;
        for(int i = 0; i<pattern.size(); i++){
            if(map.find(pattern[i]) == map.end()){
                if(set.find(words[i]) != set.end()) return false;
                map[pattern[i]] = words[i];
                set.insert(words[i]);
            }
            else if(map[pattern[i]] != words[i]) return false;
        }
        return true;
    }
};