class Solution {
public:
// A good mental trick: if your else branch would ever want to set r = mid (keeping mid as still-possibly-correct), you're in Template 2 territory and must use l < r. If every branch strictly discards mid (mid ± 1), you're in Template 1 and should use l <= r.

// Pick one template per problem and stay consistent within it — don't mix r = mid with l <= r, that's the classic source of infinite loops or missed answers.
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while(l <= r){
            int m = l + (r - l) / 2;
            int mid = nums[m];
            int left = nums[l];
            int right = nums[r];
            if(target == mid) return m;
            if(mid > right){
                if(target >= left && target < mid) r = m-1;
                else l = m+1;
                
            }
            else if(mid < left){
                if(target <= right && target > mid) l = m+1;
                else r = m-1;
            }
            else{
                if(target < mid) r = m-1;
                else l = m+1;
            }
        }
        return -1;
    }
};