class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<double> time(n,0);
        vector<pair<int,double>> cars(n);
        stack<int> s;
        for(int i = 0; i< n; i++){
            time[i] = (double)(target - position[i]) / speed[i];
            cars[i] = make_pair(position[i], time[i]);
        }
        sort(cars.begin(),cars.end());
        for(int i = n - 1; i>= 0; i--){
            if(!s.empty() && cars[i].second <= cars[s.top()].second){
                continue;
            }
            else if(!s.empty() && cars[i].second > cars[s.top()].second){
                s.push(i);
            }
            else{
                s.push(i);
            }
        }
        return s.size();
    }
};