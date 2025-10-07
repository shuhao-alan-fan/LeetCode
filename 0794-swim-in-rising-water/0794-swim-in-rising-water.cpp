class Solution {

private:
    
public:
    int swimInWater(vector<vector<int>>& grid) {
        int dRow[] = {0,0,-1,1};
        int dCol[] = {-1,1,0,0};
        int n= grid.size();
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        priority_queue<Cell> b;
        Cell cur = Cell(0,0,grid[0][0]);
        visited[0][0] = true;
        b.push(cur);
        
        int max_val = INT_MIN;
        while(!b.empty()){
            Cell cur = b.top();
            int cur_row = cur.row;
            int cur_col = cur.col;
            
            b.pop();
            cout<<cur.val<<endl;
            max_val = max(max_val, cur.val);
            if(cur_row == n-1 && cur_col == n-1){
                return max_val;
            }
            for(int i = 0; i<4; i++){
                int new_row = cur_row + dRow[i];
                int new_col = cur_col + dCol[i];
                if(isValid(new_row, new_col,n) && !visited[new_row][new_col]){
                    visited[cur_row][cur_col] = true;
                    b.push(Cell(new_row, new_col, grid[new_row][new_col]));
                }
            }
            
        }
        
        return max_val;
    }
    private:
    class Cell{
        public:
            int row;
            int col;
            int val;

            Cell(int row, int col, int val):row(row),col(col),val(val) {}

            bool operator<(const Cell& other)const{
                return val >= other.val;
            }            
    };
    bool isValid(int row, int col, int n){
        if(row < 0 || row >= n || col <0 || col >= n)
            return false;
        return true;
    }
    
};

