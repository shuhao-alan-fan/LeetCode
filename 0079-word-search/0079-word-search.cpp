class Solution {
public:
    
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        for(int i = 0; i<row; i++){
            for(int j = 0; j< col; j++){
                if(dfs(i,j,0,word,board)){
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(int i, int j, int idx,string word,vector<vector<char>>& board){
        int row = board.size();
        int col = board[0].size();
        int s = word.size();
        if(i< 0 || i>= row || j>= col || j < 0 || idx >= s || board[i][j] != word[idx]){
            return false;
        }
        if(idx == s-1 && board[i][j] == word[idx]) return true;
        char c = board[i][j];

        board[i][j] = '*';
        bool res = dfs(i-1,j,idx+1,word,board) || dfs(i+1,j,idx+1,word,board) 
        || dfs(i,j-1,idx+1,word,board) || dfs(i,j+1,idx+1,word,board);

        board[i][j] = c;
        return res;

    }
};