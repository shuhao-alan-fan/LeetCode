
class Solution {
public:
    
    
    int trapRainWater(vector<vector<int>>& heightMap) {
         // Direction arrays
        int dRow[4] = {0, 0, -1, 1};
        int dCol[4] = {-1, 1, 0, 0};

        int m = heightMap.size(), n = heightMap[0].size();

        priority_queue<Cell> boundary;
        vector<vector<bool>> visited(m,vector<bool>(n,false));

        for(int i = 0; i<m; i++){
            boundary.push(Cell(i,0,heightMap[i][0]));
            boundary.push(Cell(i,n-1,heightMap[i][n-1]));
            visited[i][0] = visited[i][n-1] = true;
        }

        for(int j = 0; j<n; j++){
            boundary.push(Cell(0,j,heightMap[0][j]));
            boundary.push(Cell(m-1,j,heightMap[m-1][j]));
            visited[0][j] = visited[m-1][j] = true;
        }
        int ans = 0;
        while(!boundary.empty()){
            Cell cur = boundary.top();
            boundary.pop();
            
            int cur_row = cur.row;
            int cur_col = cur.col;
            //currently minimum boundary height
            int cur_height = cur.height;
           
            for(int i = 0; i< 4; i++){
                int new_row = cur_row + dRow[i];
                int new_col = cur_col + dCol[i];
                Cell n_c = Cell(new_row,new_col,0);
                if(!n_c.isValid(m,n) || visited[new_row][new_col]){
                    continue;
                }
                int new_height = heightMap[new_row][new_col];
                visited[new_row][new_col] = true;

                if(new_height < cur_height){
                    cout<< new_height << cur_height <<endl;
                    ans += (cur_height - new_height);
                }
                boundary.push(Cell(new_row,new_col,max(new_height,cur_height)));
            }
        }
        return ans;


    }
    private: 
        class Cell{
            public:
                int row;
                int col;
                int height;

                Cell(int row, int col, int height): height(height),row(row), col(col) {}

                bool operator<(const Cell& other)const{
                    return height >= other.height;
                }

                bool isValid(int row, int col){
                    if(this->row < 0 || this->row >= row || this->col <0 || this->col >= col){
                        return false;
                    }
                    return true;
                }
        };
};