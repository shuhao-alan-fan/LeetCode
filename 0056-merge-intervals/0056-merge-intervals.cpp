class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int prev_start = intervals[0][0];
        int prev_end = intervals[0][1];
        for(int i = 0; i< intervals.size(); i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(start <= prev_end){
                prev_end = max(prev_end, end);
            }
            else{
                ans.push_back({prev_start,prev_end});
                prev_start = start;
                prev_end = end;
            }
        }
        ans.push_back({prev_start,prev_end});
        return ans;
    }
};