class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return false;
        unordered_map<char,char> map = {{')','('},
                                        {']','['},
                                        {'}','{'}
        };
        stack<char> a;
        for(char i:s){
            if(map.find(i) == map.end()){
                a.push(i);

            }
            else{
                if(a.empty()) return false;
                if(map[i] != a.top()) return false;
                a.pop();
            }
            
        }
        return a.empty();
    }
};