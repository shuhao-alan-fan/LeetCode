class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        int LCS[m+1][n+1];
        string ans;
        memset(LCS,0,sizeof(LCS));
        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                if(text1[i-1] == text2[j-1]) LCS[i][j] = LCS[i-1][j-1] +1;
                else{
                    LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
                }
            }
        }
        return LCS[m][n];
    }
};