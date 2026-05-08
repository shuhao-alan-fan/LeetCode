class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int left = 0, right = matrix[0].size() - 1;
        int up = 0, down = matrix.size() - 1;
        while(left<=right && up <=down ){
            
            for(int i = left; i<=right; i++){
                ans.push_back(matrix[up][i]);
            }
            up++;
            for(int j = up; j<=down; j++){
                ans.push_back(matrix[j][right]);
            }
            right--;
            if(up <= down){
                for(int i = right; i>=left; i--){
                    ans.push_back(matrix[down][i]);
                }
                down--;
            }

            if(left <= right){
                for(int j = down; j>=up; j--){
                    ans.push_back(matrix[j][left]);
                }
                left++;
            }
            
            
        }
        return ans;
    }
};