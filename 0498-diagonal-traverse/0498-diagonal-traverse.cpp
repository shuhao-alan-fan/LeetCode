class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> res;
        int k = 0;
        while(k< m+n-1){
            if(k%2 == 0){
                int r = min(k,m-1);
                int c = k-r;
                while(r>=0 && c<n){
                    res.push_back(mat[r--][c++]);
                }
            }
            else{
                int c = min(k,n-1);
                int r = k-c;
                while(r<m && c>=0){
                    res.push_back(mat[r++][c--]);
                    
                }
            }
            k++;
        }
        return res;
    }
};