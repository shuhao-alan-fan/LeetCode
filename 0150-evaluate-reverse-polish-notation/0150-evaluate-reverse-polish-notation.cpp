class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> set = {"+","-","*","/"};
        stack<int> s;
        for(string tok : tokens){
            if(!set.contains(tok)){
                s.push(stoi(tok));
            }
            else{
                int op2 = s.top();
                s.pop();
                int op1 = s.top();
                s.pop();
                int ans;
                if(tok == "+") ans = op1 + op2;
                if(tok == "-") ans = op1 - op2;
                if(tok == "*") ans = op1 * op2;
                if(tok == "/") ans = op1 / op2;
                s.push(ans);
            }
        }
        return s.top();
    }
};