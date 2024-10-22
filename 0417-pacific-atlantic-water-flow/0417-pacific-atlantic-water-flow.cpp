class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<bool>> pacific(row,vector<bool>(col));
        vector<vector<bool>> atlantic(row,vector<bool>(col));
        for(int i = 0; i< row; i++){
            dfs(heights,pacific,i,0,heights[i][0]);
            dfs(heights,atlantic,i,col-1,heights[i][col-1]);
        }
        for(int i = 0; i< col; i++){
            dfs(heights,pacific,0,i,heights[0][i]);
            dfs(heights,atlantic,row - 1,i,heights[row - 1][i]);
        }

        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }


    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j, int prev){
        int row = heights.size();
        int col = heights[0].size();
        if(i<0 || i == row || j<0 || j==col || visited[i][j] || heights[i][j] < prev) return;
        visited[i][j] = true;
        
        dfs(heights,visited,i-1,j,heights[i][j]);
        dfs(heights,visited,i+1,j,heights[i][j]);
        dfs(heights,visited,i,j-1,heights[i][j]);
        dfs(heights,visited,i,j+1,heights[i][j]);
        
    }
};