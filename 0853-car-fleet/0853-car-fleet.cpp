class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> car;
        for(int i = 0; i<position.size(); i++){
            car.push_back({position[i], speed[i]});
        }
        sort(car.rbegin(),car.rend());
        vector<double> time;
        for(int i = 0; i<car.size(); i++){
            time.push_back(double(target - car[i].first) / car[i].second);
        }
        int ans = 0;
        double prev_fleet = 0;
        for(double i:time){
            if(i > prev_fleet){
                prev_fleet = i;
                ans++;
            }
        }
        return ans;
    }
};