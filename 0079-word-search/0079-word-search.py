class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        row = len(board)
        col = len(board[0])
        s = len(word)
        def dfs(i,j,idx):
            if(i<0 or i>=row or j<0 or j>=col or idx >= s or board[i][j] != word[idx]):
                return False
            if(board[i][j] == word[idx] and idx == len(word) - 1):
                return True
            c = board[i][j]
            board[i][j] = '*'
            res = dfs(i-1,j,idx+1) or dfs(i+1,j,idx+1) or dfs(i,j-1,idx+1) or dfs(i,j+1,idx+1)
            board[i][j] = c
            return res


        for i in range(row):
            for j in range(col):
                if(dfs(i,j,0)):
                    return True

        return False