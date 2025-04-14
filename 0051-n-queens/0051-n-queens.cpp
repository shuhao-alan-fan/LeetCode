class Solution {
    public:
        vector<vector<string>> solveNQueens(int n) {
            vector<vector<string>> ans;
            vector<string> board(n, string(n,'.'));
            vector<bool> column(n, false);
            vector<bool> diag1(2*n - 1, false);
            vector<bool> diag2(2*n - 1, false);
            solve(ans,0,board,column,diag1,diag2,n);
            return ans;
        }

    private:
        void solve(vector<vector<string>>& ans, int row, vector<string>& board, 
            vector<bool>&column, vector<bool>&diag1, vector<bool>&diag2, int n){
            if(row >= n){
                ans.push_back(board);
                return;
            }
            for(int col = 0; col<n; col++){
                if(column[col] || diag1[col+row] || diag2[col-row+n-1]) continue;
                board[row][col] = 'Q';
                column[col] = diag1[col+row] = diag2[col-row + n - 1] = true;
                solve(ans,row+1,board,column, diag1,diag2,n);
                board[row][col] = '.';
                column[col] = diag1[col+row] = diag2[col-row + n - 1] = false;
            }
            

        }
};