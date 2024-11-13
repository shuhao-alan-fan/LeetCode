class TimeMap {
public:
    
    unordered_map<string,vector<pair<string,int>>> Tmap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        Tmap[key].push_back(make_pair(value,timestamp));
    }
    
    string get(string key, int timestamp) {
        if(Tmap.find(key) == Tmap.end()) return "";
        
        int low = 0, high = Tmap[key].size() - 1;
        string ans = "";
        while(low <= high){
            int m = low + (high - low)/2;
            if(Tmap[key][m].second <= timestamp){
                low = m + 1;
                ans = Tmap[key][m].first;
            }
            else{
                high = m - 1;
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */