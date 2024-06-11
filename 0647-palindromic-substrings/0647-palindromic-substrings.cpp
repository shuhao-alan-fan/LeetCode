class Solution {
public:
    int countSubstrings(string s) {
        //brute foce O(n^2)
        /*int count = 0, l = 0, counter  =s.size();
        int r =0;
        for(int l = 0; l<s.size(); l++){
            for(int r = l; r<s.size(); r++){
                if(isPalindrome(s.substr(l,r-l+1))) {
                    // cout<<s.substr(l,r-l+1)<<l<<r<<endl;
                    count++;
                }
            }
                
            
        }
        */
        //DP
        int n = s.size();
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for(int i = 1; i<n; i++){
            dp[i] = dp[i-1] + 1;
            for(int j = 0; j<i; j++){
                dp[i]+=isPalindrome(s.substr(j,i-j+1));
            }
           
        }
        return dp[n-1];
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