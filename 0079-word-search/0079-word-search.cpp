class Solution {
public:
    int row;
    int col;
    int s;
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        s = word.size();
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
        if(i< 0 || i>= row || j>= col || j < 0 || idx >= s || board[i][j] != word[idx]){
            return false;
        }
        // cout<<board[i][j]<<endl;
        // if(idx == s-1 && board[i][j] == word[idx]) return true;
        
        // for(auto iterator :v){
        //     if(iterator.first == i && iterator.second == j) return false;
        // }
        if(idx == s-1 && board[i][j] == word[idx]) return true;
        char c = board[i][j];

        board[i][j] = '*';
        bool res = dfs(i-1,j,idx+1,word,board) || dfs(i+1,j,idx+1,word,board) 
        || dfs(i,j-1,idx+1,word,board) || dfs(i,j+1,idx+1,word,board);

        board[i][j] = c;
        return res;

    }
};