class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), count = 0;
        for(int i  = 0; i<n*2 - 1; i++){
            int l = i/2;
            int r = (i+1)/2;
            while(r<n && l>=0 && s[l] == s[r]){
                count++;
                l--;
                r++;
            }
        }
        return count;
    }
};