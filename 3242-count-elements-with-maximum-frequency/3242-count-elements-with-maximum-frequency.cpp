class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> map;
        vector<int> list;
        
        for(int i: nums){
            map[i]++;
        }
        for(auto i: map){
            list.push_back(i.second);
        }

        sort(list.begin(),list.end());
        int max_freq = list[list.size()-1];
        int ans = max_freq;
        for(int i = list.size() - 2; i>=0; i--){
            if(list[i] == max_freq){
                ans += list[i];
            }
        }
        return ans;
    }
};