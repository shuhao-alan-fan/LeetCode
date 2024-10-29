class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int max_l = height[l], max_r = height[r];
        int count = 0;
        while(l<r){
            if(max_l <= max_r){
                l++;
                int a = max_l - height[l];
                if(a > 0) count += a;
                max_l = max(max_l, height[l]);
                
            }else{
                r--;
                int b = max_r - height[r];
                if(b > 0) count += b;
                max_r = max(max_r, height[r]);
            }
           
        }
        return count;
    }
};