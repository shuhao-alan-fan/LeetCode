class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>&a, vector<int>&b){
            return a[1]<b[1];
        });
        int prev_end = INT_MIN;
        int ans = 0;
        for(int i = 0;i <intervals.size(); i++){
            int cur_start = intervals[i][0];
            if(cur_start < prev_end){
                cout<<cur_start<<intervals[i][1]<<endl;
                ans++;
            }
            else{
                prev_end = intervals[i][1];
            }
        }
        return ans;
    }
};