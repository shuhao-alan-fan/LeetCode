class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        unordered_map<int,bool> visited(n);
        int count = 0;
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i = 0; i<n; i++){
            if(visited[i]) continue;
            else{
                count++;
                dfs(adj,i,visited);
            }
            
        }
        return count;
    }
    void dfs(vector<vector<int>>& adj, int i, unordered_map<int,bool>& visited){
        if(visited[i]) return;
        visited[i] = true;
        for(auto j : adj[i]){
            dfs(adj,j,visited);
        }
        return;
    }

};
