class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        ans = []
        left = 0
        right = len(matrix[0])
        top = 0
        bot = len(matrix)
        while left <= right and bot >= top:
            for j in range(left,right):
                ans.append(matrix[top][j])
            top += 1
            #last column
            for i in range(top,bot):
                ans.append(matrix[i][right-1])
            right -= 1
            #last row
            for j in range(right-1, left-1, -1):
                ans.append(matrix[bot-1][j])
            bot -= 1
            #fisrt column
            for i in range(bot-1, top-1, -1):
                ans.append(matrix[i][left])
            left += 1
        return ans[:len(matrix[0])*len(matrix)]