class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // unordered_map<char,int> dict;
        int n = s1.size();
        if(s2.size() < n) return false;
        unordered_set<char> empt;
        for(char c:s1){
            empt.insert(c);
            // dict[c]++;
        }
        
        int left = 0, right = left + n - 1;
        while(left < s2.size() - n + 1){
            while(left < s2.size() - n + 1 && !empt.count(s2[left])) left++;
            if(permutation(s1, s2.substr(left,n))){
                return true;
            }
            left++;
        }
        
        return false;
    }
    bool permutation(string a, string b){
        if(a.size() != b.size()) return false;
        unordered_map<char,int> count(26);
        for(int i = 0; i< a.size(); i++){
            count[a[i]]++;
            count[b[i]]--;
        }
        for(auto& [ch,co] : count){
            if(co != 0) return false;
        }
        return true;
    }
};