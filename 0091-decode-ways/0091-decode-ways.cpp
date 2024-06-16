class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()||s[0] == '0') return 0;
        vector<int> dp(s.size()+1,0);
        dp[0] = 1;
        for(int i = 0; i< s.size(); i++){
            if(s[i] != '0') dp[i+1] += dp[i];
            if(i>0){
                int a = stoi(s.substr(i-1,2));
                cout<<a<<endl;
                if(a>=10 && a<=26) {
                    dp[i+1] += dp[i-1];
                }
            }
            
        }
        
        
        return dp[s.size()];
    }
};