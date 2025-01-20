class KthLargest {
public:
    int K;
    priority_queue<int> q;
    KthLargest(int k, vector<int>& nums) {
        //big heap
        
        K = k;
        for(int i: nums){
           add(i);
        }
    }
    
    int add(int val) {
       if(q.size() < K){
            q.push(-1 * val);
       }
       else{
            if(-1 * val < q.top()){
                q.pop();
                q.push(-1* val);
            }
       }
       return -1 * q.top();
       
       
       
    }
};