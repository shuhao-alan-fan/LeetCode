class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> tmap;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        tmap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto& nums =tmap[key];
        int left = 0, right = nums.size() - 1;
        int target = -1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid].first <= timestamp){
                target = max(target, mid);
            }
            if(nums[mid].first < timestamp) left = mid + 1;
            else right = mid - 1;
        }
        return target == -1 ? "" : nums[target].second;
    }

};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */