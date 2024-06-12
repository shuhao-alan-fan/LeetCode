class Solution {
public:
    int countSubstrings(string s) {
       
        int n = s.size();
        int count = 0;
        for(int i=0; i<n*2-1; i++){
            int l = i/2;
            int r = (i+1)/2;
            while(l>=0 && r<n && s[l] == s[r]){
                count++;
                l--;
                r++;
            }
        }
        return count;
    }
    int isPalindrome(string s){
        int n = s.size();
        if(n == 1) return 1;
        if(n == 0) return 0;
        string r = s;
        reverse(s.begin(),s.end());
        if (r == s) return 1;
        return 0;
    }
};