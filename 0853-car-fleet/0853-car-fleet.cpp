class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> v;
        vector<double> time;
        for(int i = 0; i< position.size(); i++){
            v.push_back({position[i],speed[i]});
        }
        sort(v.rbegin(),v.rend());
        for(auto& [p,s] : v){
            time.push_back(double(target - p) / s);
        }
        
        int ans = 0;
        double prev_time = 0.0;
        for(int i = 0; i< time.size(); i++){
            if(time[i] > prev_time){
                ans++;
                prev_time = time[i];
            }
        }
        return ans;
            
        
        
        

    }
};