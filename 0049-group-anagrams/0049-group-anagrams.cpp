class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        vector<vector<string>> ans;
        for(string str: strs){
            string temp = str;
            sort(str.begin(),str.end());
            map[str].push_back(temp);
            
        }
        for(auto& [list,vec]:map){
            ans.push_back(vec);
        }
        return ans;
    }
};