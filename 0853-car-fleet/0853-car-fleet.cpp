class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> p_map;
        vector<double> time;
        for(int i = 0; i<position.size(); i++){
            p_map.push_back({position[i], speed[i]});
        }
        sort(p_map.rbegin(), p_map.rend());
        for(int i = 0; i<p_map.size(); i++){
            time.push_back(double(target - p_map[i].first) / p_map[i].second);
        }
        int fleets = 1;
        double cur_fleet = time[0];
        for(int i = 1; i<time.size(); i++){
            if(time[i] > cur_fleet){
                fleets++;
                cur_fleet = time[i];
            }
        }
        return fleets;
    }
};


//16 12 11 8 7
//10 9  9  6 7

//.1 .5 .6 1.5 1.29 