class TimeMap {
private:
    unordered_map<string, vector<pair<string,int>>> time_map;
    int binary_search(vector<int> nums, int target)
    {
        int left = 0, right = nums.size();
        if(target < nums[left]) return -1;
        while(left < right){
            int mid = left + (right - left)/2;
            if(nums[mid] > target) right = mid;
            else left = mid + 1;
        }
        if(left - 1 >= 0) return nums[left - 1];
        return -1;
    }
public:
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        time_map[key].push_back(make_pair(value,timestamp));
    }
    
    string get(string key, int timestamp) {
        if(time_map.find(key) == time_map.end()) return "";
        
        int left = 0, right = time_map[key].size();
        while(left < right){
            int mid = left + (right - left) /2;
            if(time_map[key][mid].second > timestamp) right = mid;
            else left = mid + 1;
        }
        
        if(left - 1 < 0) return "";

        return time_map[key][left-1].first;

        
        
    }

    
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */