class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> arr;
        if (r*c != m*n){
            return mat;
        }
        for(int i = 0; i<m; i++){
            for(int j = 0;j<n; j++){
                arr.push_back(mat[i][j]);
            }
        }
        int k = 0;
        vector<vector<int>> res(r, vector<int>(c,0));
        for(int i = 0; i<r; i++){
            for(int j = 0;j<c; j++){
                res[i][j] = arr[k++];
            }
        }
        return res;
    }
};