#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    /* create a max heap and store the frequent and number pair*/
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto it = freq.begin(); it != freq.end(); it++) {
            pq.push(make_pair(it->second, it->first));
        }
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};