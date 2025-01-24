class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for(int i: nums){
            if(q.size() < k){
                q.push(-1 * i);
            }
            else if(q.top() > -1*i){
                q.pop();
                q.push(-1*i);
            }
        }
        return -1 * q.top();
    }   
};