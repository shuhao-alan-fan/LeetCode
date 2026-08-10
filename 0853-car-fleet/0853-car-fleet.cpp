class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int ans = 1;
        vector<pair<int,int>> v;
        vector<double> time;
        
        for(int i = 0; i<position.size(); i++){
            v.push_back(make_pair(position[i],speed[i]));
        }
        sort(v.rbegin(),v.rend());
        for(auto&[pos,vel]: v){
            time.push_back(double(target - pos) / vel);
        }
        double f_time = time[0];
        for(int i = 1; i<time.size(); i++){
            if(f_time < time[i]){
                ans++;
                f_time = time[i];
            }
            
        }
        return ans;
    }
};