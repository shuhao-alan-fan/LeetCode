class Solution {
public:
    
  
    void dfs(int sP, int eP, string s, int n, vector<string>& res){
        cout<<sP<<" "<<eP<<endl;

        if(sP + eP == 2*n && sP == eP ){
            res.push_back(s);
            return;
        }
         if(sP < n){
            dfs(sP+1,eP,s+"(", n,res);
        }
         if (eP < sP){
            dfs(sP,eP+1, s+")", n,res);
        }

        
    }
      vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s = "";
        dfs(0,0,s,n,res);
        return res;
    }
};