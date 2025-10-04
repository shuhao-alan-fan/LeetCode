class Solution {
public:
    int maxArea(vector<int>& height) {
        //brute force: O(N^2) 
        // int ans = INT_MIN;
        // for(int i = 0; i<height.size(); i++){
        //     for(int j = i+1; j < height.size(); j++){
        //         int area = min(height[i],height[j]) * (j-i);
        //         ans = ans > area ? ans : area;
        //     }
        // }
        // return ans;

        //Optimization two Pointers O(N)
        int l = 0, r = height.size() - 1;
        int ans = INT_MIN;
        while(l < r){
            int tall = 0;
            int len = r - l;
            if(height[l] <= height[r]){
                tall = height[l];
                l++;
            }
            else{
                tall = height[r];
                r--;
            }
            int area = tall * len;
            ans = max(ans,area);
        }
        return ans;
    }
};