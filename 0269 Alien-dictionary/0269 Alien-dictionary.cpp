class Solution {
public:
//topological sort
    string foreignDictionary(vector<string>& words) {
        
        unordered_set<char> s;
        for(string str :words){
            for(char c :str){
                s.insert(c);
            }
        }
        unordered_map<char,bool> visited(s.size());
        vector<char> res;
        unordered_map<char,vector<char>> adj(s.size());
        for(int i = 0; i<words.size()-1; i++){
            string w1 = words[i];
            string w2 = words[i+1];
            int min_len = min(words[i].size(), words[i+1].size());
            if(w1.size() > w2.size() && w1.substr(0,min_len) == w2.substr(0,min_len)){
                return "";
            }
            for(int j = 0; j<min_len; j++){
                if(w1[j] != w2[j]){
                    adj[w1[j]].push_back(w2[j]);
                    break;
                }
            }
        }
        for(auto c: s){
            if(dfs(c,visited,res,adj)){
                return "";
            }
        }
        string ans = "";
        for(int i = res.size()-1; i>=0; i--){
            cout<<res[i]<<endl;
            ans += (res[i]);
        }
        return ans;
    }


    bool dfs(char c, unordered_map<char,bool>& visited, vector<char>& res, unordered_map<char,vector<char>>& adj){
        if(visited.find(c) != visited.end()){
            return visited[c];
        }
        visited[c] = true;

        for(char i: adj[c]){
            if(dfs(i,visited,res,adj)){
                return true;
            }
        }
        visited[c] = false;
        res.push_back(c);
        return false;
    }
};
