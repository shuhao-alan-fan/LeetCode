class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> sta;
        int n = temperatures.size();
        vector<int> ans(n);
        for(int i = 0; i<temperatures.size(); i++){
            int cur_temp = temperatures[i];
            while(!sta.empty() && cur_temp > sta.top().first){
                ans[sta.top().second] = i - sta.top().second;
                sta.pop();
            }
            sta.push({cur_temp,i});
        }
        return ans;
    }
};