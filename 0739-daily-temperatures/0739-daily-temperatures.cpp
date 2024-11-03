class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        // stack stores the index of temp
        stack<int> s;
        vector<int> res(n,0);
        for(int i=0; i<n; i++){
            while(!s.empty() && temperatures[i] > temperatures[s.top()]){
                res[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
            
        }
        // }
        /*naive: TLE
        int i = 0;
        while(i < n){
            for(int j = i+1; j<n; j++){
                if(temperatures[i] >= temperatures[j] ){
                    // cout<<temperatures[i]<<endl;
                    res[i] ++;
                    // cout<<res[i]<<endl;
                    if(j == n - 1){
                        res[i] = 0;
                    }
                }
                else{
                    res[i]++;
                    break;
                }
            }
            i++;
        }
        */
    //    cout<<s.size()<<endl;
        return res;
    }
};