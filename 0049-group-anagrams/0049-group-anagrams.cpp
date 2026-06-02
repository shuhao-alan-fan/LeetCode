class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // how to compare the chars between two strings
        unordered_map<string,vector<string>> mp;
        for(string s:strs){
            string unsort = s;
            sort(s.begin(),s.end());
            mp[s].push_back(unsort);
        }
        vector<vector<string>> ans;
        for(const auto & [ana,list] : mp){
            ans.push_back(list);
        }
        return ans;
        
    }
};