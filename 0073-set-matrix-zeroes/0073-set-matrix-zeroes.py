class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # having a set to store all the col and row
        Row = len(matrix)
        Col = len(matrix[0])
        row_s = set()
        col_s = set()
        for i in range(Row):
            for j in range(Col):
                if matrix[i][j] == 0:
                    row_s.add(i)
                    col_s.add(j)
        for i in row_s:
            for j in range(Col):
                matrix[i][j] = 0

        for i in col_s:
            for j in range(Row):
                matrix[j][i] = 0
                
        return