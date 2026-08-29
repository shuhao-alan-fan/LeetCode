class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> temp_index;
        vector<int> ans(temperatures.size(),0);
        for(int i = 0; i<temperatures.size(); i++){
            while(!temp_index.empty() && temperatures[i] > temp_index.top().first ){
                int index = temp_index.top().second;
                temp_index.pop();
                ans[index] = i - index;
            }
            temp_index.push({temperatures[i], i});
        }
        return ans;

    }
};