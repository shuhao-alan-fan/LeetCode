class Solution {
public:
    void func(int op,int cp,vector<string> &res,string s,int n){
        if(op==cp && s.size()==2*n){
            res.push_back(s);
            return;
        }
        if(op<n){
            func(op+1,cp,res,s+"(",n);
        }
        if(cp<op){
            func(op,cp+1,res,s+")",n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        func(0,0,res,s,n);
        return res;
    }
};