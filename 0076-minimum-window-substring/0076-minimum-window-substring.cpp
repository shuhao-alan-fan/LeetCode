class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int,int> tmap;
        if(s.size() < t.size() || s == "" || t == "") return "";
        // unordered_map<int,int> smap;
        int cnt = t.size();
        pair<int,int> best = {0,s.size()};
        for(char c: t){
            tmap[c]++;
        }
        int left = 0;
        for(int right = 0; right< s.size(); right++){
            
            if(tmap.count(s[right])){
                if(tmap[s[right]] > 0) cnt--;
                tmap[s[right]]--;
                
            }

            while(cnt == 0){
                if(right - left + 1 < best.second - best.first + 1){
                    best = {left,right};
                }
                if(tmap.count(s[left])){   
                    tmap[s[left]]++;
                    if(tmap[s[left]] > 0) cnt++;
                }
                left++;
            }
        }
        return best.second - best.first == s.size() ? "" : s.substr(best.first, best.second - best.first + 1);
    }
};