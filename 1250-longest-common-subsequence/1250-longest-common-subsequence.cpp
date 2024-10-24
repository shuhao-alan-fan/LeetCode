class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        string s;
        vector<vector<int>> dp(m, vector<int>(n,0));
        for(int i = 0; i<m; i++){
            for(int j = 0; j< n ; j++){
                if(text1[i] == text2[j]){
                    s+= text1[i];
                    if(i == 0 || j == 0){
                        dp[i][j] = 1;

                    }
                    else{
                        dp[i][j] = dp[i-1][j-1] + 1;
                    }
                    
                }
                else{
                    if(i > 0 && j == 0){
                        dp[i][j] = dp[i-1][j];
                    }
                    else if(i == 0 && j > 0){
                        dp[i][j] = dp[i][j-1];
                    }
                    else{
                        if(i > 0 && j > 0) dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
        }
        cout<<s<<endl;
        return dp[m-1][n-1];
    }
};