class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int operand;
        stack<int> s;
        for(int i = 0; i<tokens.size(); i++){
            //if operands, dont push
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                if(tokens[i] == "+"){
                    s.push(b+a);
                }
                else if(tokens[i] == "-"){
                    s.push(b-a);
                }
                else if(tokens[i] == "*"){
                    s.push(b*a);
                }
                else if(tokens[i] == "/"){
                    s.push(b/a);
                }
            }
            else{
                s.push(stoi(tokens[i]));
            }
            
        }
        return s.top();        
    }

};