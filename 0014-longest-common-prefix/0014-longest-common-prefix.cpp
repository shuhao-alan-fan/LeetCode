class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int a = 0;
        int n = strs.size();
        while(a < strs[0].size()){
            if(strs[0][a] == strs[n-1][a]){
                a++;
            }
            else{   
                return strs[0].substr(0,a);
            }
        }
        return strs[0].substr(0,a);
    }
};