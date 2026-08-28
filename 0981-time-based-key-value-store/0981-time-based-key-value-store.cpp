class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> tmap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        tmap[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(tmap.find(key) == tmap.end()) return "";
        auto& v = tmap[key];
        int left = 0, right = v.size() - 1;
        int ans = -1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(v[mid].first <= timestamp){
                ans = max(mid,ans);
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        if(ans == -1) return "";
        return v[ans].second;

    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */