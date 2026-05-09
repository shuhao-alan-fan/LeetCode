class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> grid(n,vector<int>(n,0));
        int up = 0, down = n-1;
        int left = 0, right = n-1;
        int k = 1;
        while(up<=down && left<=right){
            for(int i = left; i<=right; i++){
                grid[up][i] = k;
                k++;
            }
            up++;
            for(int i = up; i<=down; i++){
                grid[i][right] = k;
                k++;
            }
            right--;
            if(left<=right){
                for(int i = right; i>=left; i--){
                    grid[down][i] = k;
                    k++;
                }
            }
            down--;
            if(up<=down){
                for(int i = down; i>=up; i--){
                    grid[i][left] = k;
                    k++;
                }
            }
            left++;
        }
        return grid;
    }
};