class Solution {
public:
    //slightly better >
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>&a, const vector<int> &b){
            return a[1]<b[1];
        });
        vector<int> ans;
        vector<int> q = queries;
        sort(q.begin(),q.end());
        sort(intervals.begin(), intervals.end());
        priority_queue<vector<int>> pq;
        unordered_map<int,int> res;
        int i = 0, n = intervals.size();
        for(int query : q){
            
            while(i<n && intervals[i][0] <= query){
                int l = intervals[i][0], r = intervals[i][1];
                pq.push({l-r-1,r});
                cout<<pq.top()[0]<<endl;
                i++;
            }
            while(!pq.empty() && pq.top()[1] < query){
                pq.pop();
            }
            res[query] = pq.size() ? -pq.top()[0] : -1;
        }
        for(auto i: queries){
            ans.push_back(res[i]);
        }
        return ans;
    }
};