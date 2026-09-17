class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
       
        for(string s: tokens){
            if(s.size() > 1 || isdigit(s[0])){
                st.push(stoi(s));
            }
            else{
                int op2 = st.top();  st.pop();
                int op1 = st.top();  st.pop();
                switch(s[0]){
                    case '+':
                        st.push(op1 + op2); break;
                    case '-':
                        st.push(op1 - op2); break;
                    case '*':
                        st.push(op1 * op2); break;
                    case '/':
                        st.push(op1 / op2); break;
    
                }
            }
                
        }
        return st.top();

    }
};