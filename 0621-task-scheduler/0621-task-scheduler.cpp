class Solution {
public:
    
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;
        int totalTasks = tasks.size();
        int count[26] = {0};
        for(char i: tasks){
            count[i - 'A'] ++;
        }
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i< 26; i++){
            if(count[i] > 0){
                pq.push(make_pair(count[i],i));
            }
        }
        while(!pq.empty()){
            //cycle
            vector<int> v;

            for(int i=0;i < n+1; i++){
                if(!pq.empty()){
                    auto t = pq.top();
                    pq.pop();
                    time++;
                    count[t.second]--;
                    if(count[t.second]>0){
                        v.push_back(t.second);
                    }
                }
                else if(!v.empty()){
                    time++;
                }
                
                
                // if(n >= totalTasks){
                //     time = time + n+1 - totalTasks;
                // }
                
            }
            for(int k: v){
                pq.push(make_pair(count[k],k));
            }
           
            
        }
        return time;
    }
};