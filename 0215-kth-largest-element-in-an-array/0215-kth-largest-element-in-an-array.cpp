class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i: nums){
            pq.push(i);
        }
        for(int i = 1; i<k; i++){
            pq.pop();
        }
        return pq.top();
    }
};