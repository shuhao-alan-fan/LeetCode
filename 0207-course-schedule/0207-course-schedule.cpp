class Solution {
public:
    vector<vector<int>> buildmap(int numCourses,vector<vector<int>>& prerequists){
        vector<vector<int>> adj(numCourses);

        for(auto i: prerequists){
            adj[i[0]].push_back(i[1]);
        }
        return adj;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses);
        vector<bool> recStack(numCourses);
        vector<vector<int>> adj = buildmap(numCourses,prerequisites);
        for(int i = 0; i<numCourses; i++){
            if(!visited[i] && isCycleHelper(adj,i,visited,recStack)){
                return false;
            }

        }
        return true;
    }
    bool isCycleHelper(vector<vector<int>>& adj, int cur, vector<bool>& visited, vector<bool>& recStack){
            if(cur> adj.size() - 1) return false;
            if(!visited[cur]){
                visited[cur] = true;
                recStack[cur] = true;
                for(int u : adj[cur]){
                    if(!visited[u] && isCycleHelper(adj,u,visited,recStack)){
                        return true;
                    }
                    else{
                        if(recStack[u]){
                            return true;
                        }
                    }
                }
                
            }   
            recStack[cur] = false;
            return false;
        
    }
};