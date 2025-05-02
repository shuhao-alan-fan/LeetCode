class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>> map){
        int max_val = 0;
        for(int i = 0; i<map.size(); i++){
            for(int j = 0; j<map[0].size();j++){
                if(map[i][j] == 1){
                    int temp = 0;
                    dfs(map,i,j,temp);
                    max_val = max(max_val, temp);
                }
            }
        }
        return max_val;
    }
    void dfs(vector<vector<int>>& map, int x, int y, int &temp){
        
        if(x< 0 || y < 0|| x >= map.size() || y >= map[0].size()) return;
        if(map[x][y] == 0){
            return;
        }
        map[x][y] = 0;
        temp++;
        //left 
        dfs(map, x,y-1,temp);
        //top
        dfs(map, x-1,y,temp);
        //bot
        dfs(map, x+1,y,temp);
        //right
        dfs(map, x,y+1,temp);
    }
};