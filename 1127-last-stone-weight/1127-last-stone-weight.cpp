class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(int i:stones){
            q.push(i);
        }
        while(!q.empty()){
            int a = q.top();
            q.pop();
            if(q.empty()) return a;
            int b = q.top();
            q.pop();
            if(a>b){
                q.push(a-b);
            }
        }
        return 0;
    }
    
};