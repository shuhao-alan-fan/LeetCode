class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int operand;
        stack<string> s;
        for(int i = 0; i<tokens.size(); i++){
            //if operands, dont push
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int a = stoi(s.top()); s.pop();
                int b = stoi(s.top()); s.pop();
                if(tokens[i] == "+"){
                    s.push(to_string(b+a));
                }
                else if(tokens[i] == "-"){
                    s.push(to_string(b-a));
                }
                else if(tokens[i] == "*"){
                    s.push(to_string(b*a));
                }
                else if(tokens[i] == "/"){
                    s.push(to_string(b/a));
                }
            }
            else{
                s.push(tokens[i]);
            }
            
        }
        return stoi(s.top());        
    }

};