class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n);
        vector<bool> visited_2(n);
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);          
        }
        if(isCycleHelper(0,adj,visited,0)){
            return false;
        }
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
    bool isCycleHelper(int cur, vector<vector<int>>& adj, vector<bool>& visited,int prev){
            visited[cur] = true;
            for(auto i:adj[cur]){
                if(!visited[i] && isCycleHelper(i,adj,visited,cur)){
                    return true;
                }
                else if(visited[i] && prev != i){
                    return true;
                }
            }
        
        return false;
    }
    
};
