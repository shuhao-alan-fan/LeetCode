class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> map = {{'(',')'},
                                        {'{','}'},
                                        {'[',']'}};
        stack<char> sta;
        for(char c:s){
            if(map.count(c)) sta.push(c);
            else{
                if(sta.empty() || c != map[sta.top()]){
                    return false;
                }
                sta.pop();
            }
        }
        return sta.empty();
    }
};