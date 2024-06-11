class Solution {
public:
    int countSubstrings(string s) {
        int count = 0, l = 0, counter  =s.size();
        int r =0;
        for(int l = 0; l<s.size(); l++){
            for(int r = l; r<s.size(); r++){
                if(isPalindrome(s.substr(l,r-l+1))) {
                    // cout<<s.substr(l,r-l+1)<<l<<r<<endl;
                    count++;
                }
            }
                
            
        }
        return count;
    }
    bool isPalindrome(string s){
        int n = s.size();
        if(n == 1) return true;
        if(n == 0) return false;
        string r = s;
        reverse(s.begin(),s.end());
        if (r == s) return true;
        return false;
    }
};