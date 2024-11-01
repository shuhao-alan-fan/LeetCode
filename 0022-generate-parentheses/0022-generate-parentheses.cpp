class Solution {
public:

    void f(int i, int j, int n, string &s, vector<string> &ans) {
        if (i == n && j == n) {
            ans.push_back(s);
            return;
        }
        if (i < n) {
            
            s.push_back('(');
            f(i+1,j,n,s,ans);
            s.pop_back();
        }
        if (j < n && j < i) {
            
           s.push_back(')');
            f(i,j+1,n,s,ans);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string s = "";
        vector<string> ans;
        f(0,0,n,s,ans);
        return ans;

    }
};