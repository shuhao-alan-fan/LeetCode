class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int l = 0, r = row - 1;
        int f = 0;
        while(l<=r){
            if(r == 0){
                break;
            }
            int m = l+(r-l)/2;
            // cout<< matrix[m][0] <<endl;
            if(matrix[m][0] == target) return true;
            else if(matrix[m][0] > target){
                r = m - 1;
            }
            else if(matrix[m][0] < target){
                if(matrix[m][col - 1] >= target){
                    f = m;
                    break;
                }
                else{
                    l = m+1;
                }
            }
                
        }
        int left = 0, right = matrix[f].size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            cout<<matrix[f][mid]<<endl;
            if(matrix[f][mid] == target ) return true;
            else if(matrix[f][mid] < target ) left = mid+1;
            else right = mid - 1;
        }
        return false;
    }
};