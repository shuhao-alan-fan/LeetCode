class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> sta;
        unordered_set<string> set = {"+","-","*","/"};
        for(string i:tokens){
            if(set.find(i) == set.end()){
                sta.push(stoi(i));
            }
            else{
                int res = 0;
                int op1 = sta.top();
                sta.pop();
                int op2 = sta.top();
                sta.pop();
                if(i == "+") res = op2+op1;
                else if(i == "-") res = op2-op1;
                else if(i == "*") res = op2*op1;
                else if(i == "/") res = op2/op1;
                sta.push(res);
            }
        }
        return sta.top();
    }
};