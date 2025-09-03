class Solution {
public:
    bool isValid(string s) {
        if(s.size()<=1) return false;
        unordered_map<char,char> map = {{'(',')'},
                                        {'[',']'},
                                        {'{','}'}
        };
        stack<char> a;
        for(char i:s){
            if(map.find(i) == map.end()){
                if(a.empty()) return false;
                if(map[a.top()] == i){
                    a.pop();
                }
                else{
                    return false;
                }

            }
            else{
                a.push(i);
            }
        }
        return a.empty();
    }
};