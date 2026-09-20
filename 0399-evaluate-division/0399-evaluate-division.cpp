class Solution {
public:
    unordered_map<string,vector<pair<string, double>>> graph;


    double dfs(const string& cur, const string &dest, unordered_set<string> &seen){
        if(cur == dest) return 1;
        seen.insert(cur);
        for(auto &[nxt,weight]: graph[cur]){
            if(seen.count(nxt)) continue;
            double sub = dfs(nxt,dest,seen);
            
            if(sub != -1.0) return sub*weight;
        }
        return -1;
    }



    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        for(int i = 0; i<equations.size(); i++){
            graph[equations[i][0]].push_back({equations[i][1],values[i]});
            graph[equations[i][1]].push_back({equations[i][0],1.0/values[i]});
        }
        for(auto & q:queries){
            const string &x = q[0], &y = q[1];
            if(!graph.count(x) || !graph.count(y)) ans.push_back(-1.0);
            else{
                unordered_set<string> seen;
                ans.push_back(dfs(x,y,seen));
            }
        }
        return ans;
    }
};