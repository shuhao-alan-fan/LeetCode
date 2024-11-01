class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        string s = "";
        dfs(0,0,s,n);
        return res;
    }
    void dfs(int sP, int eP, string s, int n){
        cout<<sP<<" "<<eP<<endl;

        if(sP + eP == 2*n && sP == eP ){
            res.push_back(s);
            return;
        }
         if(sP < n){
            dfs(sP+1,eP,s+"(", n);
        }
         if (eP < sP){
            dfs(sP,eP+1, s+")", n);
        }

        
    }
};