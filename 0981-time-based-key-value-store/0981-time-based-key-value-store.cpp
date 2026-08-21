class TimeMap {
private:
    unordered_map<string, vector<pair<string,int>>> time_map;
    
public:
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        time_map[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        if(time_map.find(key) == time_map.end()) return "";
        auto& entries = time_map[key];
        int left = 0, right = entries.size();
        while(left < right){
            int mid = left + (right - left) /2;
            if(entries[mid].second > timestamp) right = mid;
            else left = mid + 1;
        }
        
        if(left == 0) return "";

        return entries[left-1].first;

        
        
    }

    
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */